// ************************************************************************** //
//
//  Reflectometry simulation software prototype
//
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @authors   see AUTHORS
//
// ************************************************************************** //

#ifndef DAREFL_GRAPHEDITOR_GRAPHEDITOR_H
#define DAREFL_GRAPHEDITOR_GRAPHEDITOR_H

#include <darefl/mainwindow/editorwidget.h>

namespace ModelView
{
class GraphCanvas;
class GraphViewportItem;
} // namespace ModelView

class GraphEditorToolBar;

//! Graph editor with GraphCanvas at the center, and few control buttons on the right.

class GraphEditor : public EditorWidget
{
    Q_OBJECT
public:
    explicit GraphEditor(QWidget* parent = nullptr);

    void setItem(ModelView::GraphViewportItem* viewport_item);

private:
    ModelView::GraphCanvas* graph_canvas{nullptr};
};

#endif // DAREFL_GRAPHEDITOR_GRAPHEDITOR_H
