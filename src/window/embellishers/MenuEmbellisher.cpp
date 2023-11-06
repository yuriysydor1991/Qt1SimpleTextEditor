//
// Created by cc on 05.11.23.
//

#include "MenuEmbellisher.h"

MenuEmbellisher::MenuEmbellisher(IEditorWindow& main) : window{main} {
  entitleMenus();
  packMenus();

  window.setMainMenu(menuBar);
}

QAction& MenuEmbellisher::getFileNew() { return fileNew; }

QAction& MenuEmbellisher::getFileOpen() { return fileOpen; }

QAction& MenuEmbellisher::getFileClose() { return fileClose; }

QAction& MenuEmbellisher::getFileSave() { return fileSave; }

QAction& MenuEmbellisher::getFileSaveAs() { return fileSaveAs; }

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

  helpAbout.setText(window.t("About"));
}

void MenuEmbellisher::packMenus() {
  menuBar.addMenu(&topMFile);
  menuBar.addMenu(&topMEdit);
  menuBar.addMenu(&topMHelp);

  topMFile.addAction(&fileNew);
  topMFile.addAction(&fileOpen);
  topMFile.addAction(&fileSave);
  topMFile.addAction(&fileSaveAs);
  topMFile.addAction(&fileClose);

  topMEdit.addAction(&editCopy);
  topMEdit.addAction(&editCut);
  topMEdit.addAction(&editPaste);

  topMHelp.addAction(&helpAbout);
}
