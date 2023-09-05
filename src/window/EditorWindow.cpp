//
// Created by cc on 03.09.23.
//

#include <QFileDialog>

#include "EditorWindow.moc.h"

EditorWindow::EditorWindow()
{
  setCentralWidget (&textEdit);
  setMenuBar (&menuBar);
  setStatusBar(&statusBar);
  statusBar.addPermanentWidget(&permanentStatus, 1);

  entitleMenus();
  packMenus ();
  connectMenus();

  showStatusMessage(defaultStatus);
}

void EditorWindow::showStatusMessage(const char* status)
{
  showStatusMessage(QString(status));
}

void EditorWindow::showStatusMessage(const QString& status)
{
  permanentStatus.setText (status) ;
}

bool EditorWindow::openFile(const char* path)
{
  return openFile(QString(path));
}

bool EditorWindow::openFile(const QString& path)
{
  if (!file.fileName().isEmpty())
  { file.close(); }

  file.setFileName(path);

  if (!file.open(QIODevice::ReadWrite | QIODevice::Text))
  {
    showStatusMessage("Error while opening file: " + path);
    return false ;
  }

  while (!file.atEnd()) {
    QString line = file.readLine() ;
    line.resize(line.size() - 1);
    textEdit.append(line);
  }

  showStatusMessage(path);

  return true ;
}

bool EditorWindow::clear()
{
  textEdit.clear();
  file.close();
  file.setFileName("");

  showStatusMessage(defaultStatus);

  return true ;
}

void EditorWindow::entitleMenus()
{
  topMFile.setTitle(tr("File"));
  topMEdit.setTitle(tr("Edit"));
  topMHelp.setTitle(tr("Help"));

  fileNew.setText(tr("New"));
  fileOpen.setText(tr("Open"));
  fileSave.setText(tr("Save"));
  fileSaveAs.setText(tr("SaveAs"));
  fileClose.setText(tr("Close"));

  editCopy.setText(tr("Copy"));
  editCut.setText(tr("Cut"));
  editPaste.setText(tr("Paste"));

  helpAbout.setText(tr("About"));
}

void EditorWindow::packMenus ()
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

void EditorWindow::connectMenus()
{
  connect(&fileNew, SIGNAL(triggered()), this, SLOT(newTxt()));
  connect(&fileClose, SIGNAL(triggered()), this, SLOT(newTxt()));
  connect(&fileOpen, SIGNAL(triggered()), this, SLOT(openTxt()));
  connect(&fileSave, SIGNAL(triggered()), this, SLOT(saveTxt()));
  connect(&fileSaveAs, SIGNAL(triggered()), this, SLOT(saveTxtAs()));
}

void EditorWindow::newTxt()
{
  clear();
}

void EditorWindow::openTxt()
{
  auto filename = QFileDialog::getOpenFileName(
this,
tr("Open a text file"),
"/",
tr(defaultFileFilter)
   );

  if (!filename.isEmpty())
  { openFile(filename); }
}

void EditorWindow::saveTxt()
{
  if (file.fileName().isEmpty())
  { return ; }

  QString data = textEdit.toPlainText();

  file.write(data.toLocal8Bit());
}

void EditorWindow::saveTxtAs()
{
  QString filename = QFileDialog::getSaveFileName(this, tr("Save File As"),
                                                  "/home/",
                                                  defaultFileFilter);

  if (filename.isEmpty())
  { return ; }

  openFile(filename);

  saveTxt();
}