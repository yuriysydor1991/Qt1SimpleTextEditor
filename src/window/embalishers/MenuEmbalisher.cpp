//
// Created by cc on 05.11.23.
//

#include "MenuEmbalisher.h"

MenuEmbalisher :: MenuEmbalisher (QMainWindow& main) : window(main)
{
  entitleMenus () ;
  packMenus () ;

  window.setMenuBar (&menuBar) ;
}

QAction& MenuEmbalisher::getFileNew()
{
  return fileNew ;
}

QAction& MenuEmbalisher::getFileOpen()
{
  return fileOpen ;
}

QAction& MenuEmbalisher::getFileClose()
{
  return fileClose ;
}

QAction& MenuEmbalisher::getFileSave()
{
  return fileSave ;
}

QAction& MenuEmbalisher::getFileSaveAs()
{
  return fileSaveAs ;
}

void MenuEmbalisher::entitleMenus()
{
  topMFile.setTitle(window.tr("File"));
  topMEdit.setTitle(window.tr("Edit"));
  topMHelp.setTitle(window.tr("Help"));

  fileNew.setText(window.tr("New"));
  fileOpen.setText(window.tr("Open"));
  fileSave.setText(window.tr("Save"));
  fileSaveAs.setText(window.tr("SaveAs"));
  fileClose.setText(window.tr("Close"));

  editCopy.setText(window.tr("Copy"));
  editCut.setText(window.tr("Cut"));
  editPaste.setText(window.tr("Paste"));

  helpAbout.setText(window.tr("About"));
}

void MenuEmbalisher::packMenus ()
{
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
