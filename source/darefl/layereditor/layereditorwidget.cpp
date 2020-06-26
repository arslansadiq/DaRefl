// ************************************************************************** //
//
//  Reflectometry simulation software prototype
//
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @authors   see AUTHORS
//
// ************************************************************************** //

#include <darefl/layereditor/layereditorwidget.h>
#include <darefl/model/applicationmodels.h>
#include <darefl/layereditor/customeditorfactory.h>
#include <darefl/model/layeritems.h>
#include <darefl/layereditor/layerselectionmodel.h>
#include <darefl/layereditor/layertreeview.h>
#include <darefl/layereditor/layerviewmodel.h>
#include <darefl/model/materialmodel.h>
#include <darefl/model/samplemodel.h>
#include <QVBoxLayout>
#include <mvvm/model/modelutils.h>
#include <mvvm/viewmodel/standardviewmodels.h>
#include <mvvm/viewmodel/viewmodeldelegate.h>

LayerEditorWidget::LayerEditorWidget(ApplicationModels* models, QWidget* parent)
    : QWidget(parent), view_model(std::make_unique<LayerViewModel>(models->sampleModel())),
      selection_model(new LayerSelectionModel(view_model.get(), this)),
      layer_view(new LayerTreeView), m_delegate(std::make_unique<ModelView::ViewModelDelegate>())
{
    auto layout = new QVBoxLayout;
    layout->setContentsMargins(0, 0, 0, 0);
    layout->addWidget(layer_view);
    setLayout(layout);

    m_delegate->setEditorFactory(std::make_unique<CustomEditorFactory>(models));
    view_model->setRootSessionItem(
        ModelView::Utils::TopItem<MultiLayerItem>(models->sampleModel()));

    layer_view->setModel(view_model.get());
    layer_view->setSelectionModel(selection_model);
    layer_view->setItemDelegate(m_delegate.get());
}

LayerEditorWidget::~LayerEditorWidget() = default;

LayerSelectionModel* LayerEditorWidget::selectionModel() const
{
    return selection_model;
}
