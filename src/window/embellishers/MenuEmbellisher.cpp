//
// Created by cc on 05.11.23.
//

#include "MenuEmbellisher.h"

#include <QKeySequence>

MenuEmbellisher::MenuEmbellisher(IEditorWindow& main) : window{main} {
  entitleMenus();
  packMenus();
  setMenusShortCuts();

  window.setMainMenu(menuBar);
}

QAction& MenuEmbellisher::getFileNew() { return fileNew; }

QAction& MenuEmbellisher::getFileOpen() { return fileOpen; }

QAction& MenuEmbellisher::getFileClose() { return fileClose; }

QAction& MenuEmbellisher::getFileSave() { return fileSave; }

QAction& MenuEmbellisher::getFileSaveAs() { return fileSaveAs; }

QAction& MenuEmbellisher::getEditCopy() { return editCopy; }

QAction& MenuEmbellisher::getEditCut() { return editCut; }

QAction& MenuEmbellisher::getEditPaste() { return editPaste; }

QAction& MenuEmbellisher::getEditUndo() { return editUndo; }

QAction& MenuEmbellisher::getEditRedo() { return editRedo; }

void MenuEmbellisher::entitleMenus() {
  topMFile.setTitle(window.t("File"));
  topMEdit.setTitle(window.t("Edit"));
  topMHelp.setTitle(window.t("Help"));

  fileNew.setText(window.t("New"));
  fileOpen.setText(window.t("Open"));
  fileSave.setText(window.t("Save"));
  fileSaveAs.setText(window.t("SaveAs"));
  fileClose.setText(window.t("Close"));

  editCopy.setText(window.t("Copy"));
  editCut.setText(window.t("Cut"));
  editPaste.setText(window.t("Paste"));

  editUndo.setText(window.t("Undo"));
  editRedo.setText(window.t("Redo"));

  helpAbout.setText(window.t("About"));
}

void MenuEmbellisher::packMenus() {
  menuBar.addMenu(&topMFile);
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

  topMEdit.addAction(&editCopy);
  topMEdit.addAction(&editCut);
  topMEdit.addAction(&editPaste);
  topMEdit.addSeparator();
  topMEdit.addAction(&editUndo);
  topMEdit.addAction(&editRedo);

  topMHelp.addAction(&helpAbout);
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
}

QAction& MenuEmbellisher::getHelpAbout() { return helpAbout; }
