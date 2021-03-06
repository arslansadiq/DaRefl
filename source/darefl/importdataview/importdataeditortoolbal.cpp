// ************************************************************************** //
//
//  Reflectometry simulation software prototype
//
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @authors   see AUTHORS
//
// ************************************************************************** //

#include <QAction>
#include <QMessageBox>
#include <darefl/importdataview/importdataeditoractions.h>
#include <darefl/importdataview/importdataeditortoolbal.h>
#include <darefl/mainwindow/styleutils.h>

ImportDataEditorToolBar::ImportDataEditorToolBar(ImportDataEditorActions* editorActions,
                                                 QWidget* parent)
    : QToolBar(parent), m_editorActions(editorActions)
{
    StyleUtils::SetToolBarStyleTextBesides(this);

    auto action = new QAction("Import", this);
    action->setToolTip("Opens the data import dialog.");
    action->setIcon(QIcon(":/icons/import.svg"));
    connect(action, &QAction::triggered, this, &ImportDataEditorToolBar::invokeImportDialogRequest);
    addAction(action);

    addSeparator();

    auto add_group_action = new QAction("Add canvas", this);
    add_group_action->setToolTip(
        "Creates an empty canvas and appends it to the list.\n"
        "Canvas can hold multiple graphs, graphs can be moved between canvas.");
    add_group_action->setIcon(QIcon(":/icons/plus-box-outline.svg"));
    connect(add_group_action, &QAction::triggered, [this]() { m_editorActions->onAddDataGroup(); });
    addAction(add_group_action);

    auto merge_group_action = new QAction("Merge", this);
    merge_group_action->setToolTip("Merge several selected canvas into one.\n"
                                   "All graphs will appear on a single canvas.");
    merge_group_action->setIcon(QIcon(":/icons/set-merge.svg"));
    merge_group_action->setObjectName("merge_group_action");
    connect(merge_group_action, &QAction::triggered,
            [this]() { m_editorActions->onMergeDataGroups(); });
    addAction(merge_group_action);

    auto delete_action = new QAction("Remove", this);
    delete_action->setToolTip("Remove the currently selected item,\n"
                              "single graph or canvas with whole content.");
    delete_action->setIcon(QIcon(":/icons/beaker-remove-outline.svg"));
    connect(delete_action, &QAction::triggered, [this]() { m_editorActions->onDeleteItem(); });
    addAction(delete_action);

    addSeparator();

    auto undo_action = new QAction("Undo", this);
    undo_action->setToolTip("Undo the action last performed.");
    undo_action->setIcon(QIcon(":/icons/undo.svg"));
    connect(undo_action, &QAction::triggered, [this]() { m_editorActions->onUndo(); });
    addAction(undo_action);

    auto redo_action = new QAction("Redo", this);
    redo_action->setToolTip("Redo the action just performed.");
    redo_action->setIcon(QIcon(":/icons/redo.svg"));
    connect(redo_action, &QAction::triggered, [this]() { m_editorActions->onRedo(); });
    addAction(redo_action);

    auto empty = new QWidget(this);
    empty->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
    addWidget(empty);

    auto reset_graph_action = new QAction("Replot", this);
    reset_graph_action->setToolTip("Set plot axes to default range");
    reset_graph_action->setIcon(QIcon(":/icons/aspect-ratio.svg"));
    connect(reset_graph_action, &QAction::triggered, this,
            &ImportDataEditorToolBar::updateViewportRequest);
    addAction(reset_graph_action);
}

//! Clears canvas container, all canvas and graphs will be removed.

void ImportDataEditorToolBar::clearCanvasContainer()
{
    QMessageBox reset_message;
    reset_message.setIcon(QMessageBox::Warning);
    reset_message.setText("You are about to clear all the loaded data.");
    reset_message.setInformativeText("Are you sure you want to proceed ?");
    reset_message.setStandardButtons(QMessageBox::Yes | QMessageBox::Cancel);
    reset_message.setDefaultButton(QMessageBox::Cancel);

    if (reset_message.exec() == QMessageBox::Yes)
        m_editorActions->onClearCanvasContainer();
}
