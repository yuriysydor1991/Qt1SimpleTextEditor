//
// Created by cc on 03.09.23.
//

#include <QFileDialog>

#include "EditorWindow.moc.h"
#include "FilterCreator.h"

EditorWindow::EditorWindow() : menus(*this)
{
  setCentralWidget (&textEdit);
  setStatusBar (&statusBar) ;
  statusBar.addPermanentWidget(&permanentStatus, 1);

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

  while (!file.atEnd())
  {
    QString line = file.readLine() ;
    textEdit.insertPlainText (line) ;
  }

  showStatusMessage(path);

  return true ;
}

bool EditorWindow::clear()
{
  if (file.isOpen ())
  {
    // as the user about file close
  }

  textEdit.clear();
  file.close();
  file.setFileName("");

  showStatusMessage(defaultStatus);

  return true ;
}

void EditorWindow::connectMenus()
{
  connect(&menus.getFileNew(), SIGNAL(triggered()), this, SLOT(newTxt()));
  connect(&menus.getFileClose(), SIGNAL(triggered()), this, SLOT(newTxt()));
  connect(&menus.getFileOpen(), SIGNAL(triggered()), this, SLOT(openTxt()));
  connect(&menus.getFileSave(), SIGNAL(triggered()), this, SLOT(saveTxt()));
  connect(&menus.getFileSaveAs(), SIGNAL(triggered()), this, SLOT(saveTxtAs()));
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
    FilterCreator::defaultTxtFilter()
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
                                                  FilterCreator::defaultTxtFilter());

  if (filename.isEmpty())
  { return ; }

  openFile(filename);

  saveTxt();
}