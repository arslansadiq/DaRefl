// ************************************************************************** //
//
//  Reflectometry simulation software prototype
//
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @authors   see AUTHORS
//
// ************************************************************************** //

#ifndef DAREFL_IMPORTDATAVIEW_DATASELECTORWIDGET_H
#define DAREFL_IMPORTDATAVIEW_DATASELECTORWIDGET_H

#include <QWidget>

namespace ModelView
{
class PropertyTreeView;
}

class QTreeView;
class DataSelectionModel;
class DataViewModel;
class CollapsibleListWidget;

//! Widget to select graphs and look at their properties.
//! Occupies the left part of ImportDataEditor.

class DataSelectorWidget : public QWidget
{
    Q_OBJECT
public:
    DataSelectorWidget(DataViewModel* view_model, QWidget* parent = nullptr);

    DataSelectionModel* selectionModel() const;

signals:
    void selectionChanged();

private slots:
    void onSelectionChanged();

private:
    DataViewModel* m_viewModel{nullptr};
    DataSelectionModel* m_selectionModel{nullptr};
    QTreeView* m_selectorTree{nullptr};
    ModelView::PropertyTreeView* m_canvasPropertyEditor{nullptr};
    ModelView::PropertyTreeView* m_graphPropertyEditor{nullptr};
    CollapsibleListWidget* m_collapsibleWidget{nullptr};
};

#endif // DAREFL_IMPORTDATAVIEW_DATASELECTORWIDGET_H
