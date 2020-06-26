// ************************************************************************** //
//
//  Reflectometry simulation software prototype
//
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @authors   see AUTHORS
//
// ************************************************************************** //

#include <darefl/layereditor/layertreeview.h>
#include <QHeaderView>
#include <QMouseEvent>

LayerTreeView::~LayerTreeView() = default;

LayerTreeView::LayerTreeView(QWidget* parent) : QTreeView(parent)
{
    setAlternatingRowColors(true);
    setSelectionBehavior(QAbstractItemView::SelectRows);
    setSelectionMode(QAbstractItemView::ExtendedSelection);
    //    setTabKeyNavigation(true);
    header()->setSectionResizeMode(QHeaderView::Stretch);
}

void LayerTreeView::setModel(QAbstractItemModel* model)
{
    QTreeView::setModel(model);
    expandAll();
}
