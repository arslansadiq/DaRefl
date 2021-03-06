// ************************************************************************** //
//
//  Reflectometry simulation software prototype
//
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @authors   see AUTHORS
//
// ************************************************************************** //

#ifndef DAREFL_SLDEDITOR_SLDEDITORTOOLBAR_H
#define DAREFL_SLDEDITOR_SLDEDITORTOOLBAR_H

#include <darefl/mainwindow/editortoolbar.h>

class SLDEditorActions;

//! Material editor toolbar.

class SLDEditorToolBar : public EditorToolBar
{
    Q_OBJECT
public:
    SLDEditorToolBar(SLDEditorActions* actions, QWidget* parent = nullptr);
    ~SLDEditorToolBar() = default;

signals:
    void resetViewport();
};

#endif // DAREFL_SLDEDITOR_SLDEDITORTOOLBAR_H
