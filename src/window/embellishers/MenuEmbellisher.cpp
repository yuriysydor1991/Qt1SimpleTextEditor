/*
 * Copyright (c) 2023, Yurii Sydor (yuriysydor1991@gmail.com) kytok.org.ua
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 *     Redistributions of source code must retain the above copyright notice,
 *     this list of conditions and the following disclaimer.
 *     Redistributions in binary form must reproduce the above copyright notice,
 *     this list of conditions and the following disclaimer in the documentation
 *     and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
 * LIABLE FOR  ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES  (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON  ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT  (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS  SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#include "MenuEmbellisher.h"

#include <QKeySequence>

namespace qt5simpleted22 {

MenuEmbellisher::MenuEmbellisher(IEditorWindow &main) : window{main} {
  entitleMenus();
  packMenus();
  setMenusShortCuts();

  window.setMainMenu(menuBar);
}

QAction &MenuEmbellisher::getFileNew() { return fileNew; }

QAction &MenuEmbellisher::getFileOpen() { return fileOpen; }

QAction &MenuEmbellisher::getFileClose() { return fileClose; }

QAction &MenuEmbellisher::getFileSave() { return fileSave; }

QAction &MenuEmbellisher::getFileSaveAs() { return fileSaveAs; }

QAction &MenuEmbellisher::getEditCopy() { return editCopy; }

QAction &MenuEmbellisher::getEditCut() { return editCut; }

QAction &MenuEmbellisher::getEditPaste() { return editPaste; }

QAction &MenuEmbellisher::getEditUndo() { return editUndo; }

QAction &MenuEmbellisher::getEditRedo() { return editRedo; }

void MenuEmbellisher::entitleMenus() {
  topMFile.setTitle(window.t("File", classname));
  topMFind.setTitle(window.t("Find", classname));
  topMEdit.setTitle(window.t("Edit", classname));
  topMHelp.setTitle(window.t("Help", classname));

  fileNew.setText(window.t("New", classname));
  fileOpen.setText(window.t("Open", classname));
  fileSave.setText(window.t("Save", classname));
  fileSaveAs.setText(window.t("SaveAs", classname));
  fileClose.setText(window.t("Close", classname));

  editCopy.setText(window.t("Copy", classname));
  editCut.setText(window.t("Cut", classname));
  editPaste.setText(window.t("Paste", classname));

  editUndo.setText(window.t("Undo", classname));
  editRedo.setText(window.t("Redo", classname));

  editFind.setText(window.t("Find", classname));
  editFindBack.setText(window.t("Find backwards", classname));

  editGoTo.setText(window.t("Go to line", classname));

  helpAbout.setText(window.t("About", classname));
  helpAboutQt.setText(window.t("About Qt5", classname));
}

void MenuEmbellisher::packMenus() {
  menuBar.addMenu(&topMFile);
  menuBar.addMenu(&topMFind);
  menuBar.addMenu(&topMEdit);
  menuBar.addMenu(&topMHelp);

  topMFile.addAction(&fileNew);
  topMFile.addSeparator();
  topMFile.addAction(&fileOpen);
  topMFile.addSeparator();
  topMFile.addAction(&fileSave);
  topMFile.addAction(&fileSaveAs);
  topMFile.addSeparator();
  topMFile.addAction(&fileClose);

  topMFind.addAction(&editFind);
  topMFind.addAction(&editFindBack);
  topMFind.addSeparator();
  topMFind.addAction(&editGoTo);

  topMEdit.addAction(&editUndo);
  topMEdit.addAction(&editRedo);
  topMEdit.addSeparator();
  topMEdit.addAction(&editCopy);
  topMEdit.addAction(&editCut);
  topMEdit.addAction(&editPaste);

  topMHelp.addAction(&helpAbout);
  topMHelp.addAction(&helpAboutQt);
}

void MenuEmbellisher::setMenusShortCuts() {
  fileNew.setShortcut(QKeySequence(Qt::CTRL + Qt::Key_P));
  fileClose.setShortcut(QKeySequence(Qt::CTRL + Qt::Key_W));
  fileOpen.setShortcut(QKeySequence(Qt::CTRL + Qt::Key_O));
  fileSave.setShortcut(QKeySequence(Qt::CTRL + Qt::Key_S));
  fileSaveAs.setShortcut(QKeySequence(Qt::CTRL + Qt::SHIFT + Qt::Key_S));

  editCut.setShortcut(QKeySequence(Qt::CTRL + Qt::Key_X));
  editCopy.setShortcut(QKeySequence(Qt::CTRL + Qt::Key_C));
  editPaste.setShortcut(QKeySequence(Qt::CTRL + Qt::Key_V));
  editUndo.setShortcut(QKeySequence(Qt::CTRL + Qt::Key_Z));
  editRedo.setShortcut(QKeySequence(Qt::CTRL + Qt::SHIFT + Qt::Key_Z));
  editFind.setShortcut(QKeySequence(Qt::CTRL + Qt::Key_F));
  editFindBack.setShortcut(QKeySequence(Qt::CTRL + Qt::ALT + Qt::Key_F));
  editGoTo.setShortcut(QKeySequence(Qt::CTRL + Qt::Key_G));
}

QAction &MenuEmbellisher::getHelpAbout() { return helpAbout; }

QAction &MenuEmbellisher::getEditFind() { return editFind; }

QAction &MenuEmbellisher::getEditFindBack() { return editFindBack; }

QAction &MenuEmbellisher::getEditGoTo() { return editGoTo; }

QAction &MenuEmbellisher::getHelpAboutQt() { return helpAboutQt; }

void MenuEmbellisher::addToEdit(QMenu &newMenu) { topMEdit.addMenu(&newMenu); }

void MenuEmbellisher::removeFromEdit(QMenu &newMenu) {
  topMEdit.removeAction(newMenu.menuAction());
}

}  // namespace qt5simpleted22
