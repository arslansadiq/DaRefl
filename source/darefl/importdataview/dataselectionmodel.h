// ************************************************************************** //
//
//  Reflectometry simulation software prototype
//
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @authors   see AUTHORS
//
// ************************************************************************** //

#ifndef DAREFL_IMPORTDATAWIDGETS_DATASELECTIONMODEL_H
#define DAREFL_IMPORTDATAWIDGETS_DATASELECTIONMODEL_H

#include <QItemSelectionModel>
#include <vector>

namespace ModelView
{
class ViewModel;
class SessionItem;
class GraphItem;
}

class CanvasItem;

//! Custom selection model for data view model (AbstractViewModel).

class DataSelectionModel : public QItemSelectionModel
{
    Q_OBJECT
public:
    DataSelectionModel(ModelView::ViewModel* view_model, QObject* parent = nullptr);
    ~DataSelectionModel() = default;

    void selectItem(ModelView::SessionItem* item);
    void selectItems(std::vector<ModelView::SessionItem*> items);

    std::vector<ModelView::SessionItem*> selectedItems() const;

    const ModelView::ViewModel* viewModel() const;

    CanvasItem* activeCanvas() const;
    ModelView::GraphItem* selectedGraph() const;
};

#endif // DAREFL_IMPORTDATAWIDGETS_DATASELECTIONMODEL_H
