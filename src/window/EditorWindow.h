//
// Created by cc on 03.09.23.
//

#ifndef QT1SIMPLETEXTEDITORDEMO_EDITORWINDOW_H
#define QT1SIMPLETEXTEDITORDEMO_EDITORWINDOW_H

#include <QMainWindow>
#include <QTextEdit>
#include <QMenuBar>
#include <QMenu>
#include <QStatusBar>
#include <QLabel>
#include <QFile>
#include <QString>
#include <QAction>

class EditorWindow: public QMainWindow
{
  Q_OBJECT

public:
  EditorWindow();

  void showStatusMessage(const char* status);
  void showStatusMessage(const QString& status);

  bool openFile(const char* path);
  bool openFile(const QString& path);

  bool clear();

private slots:

  void newTxt();

  void openTxt();

  void saveTxt();

  void saveTxtAs();

private:

  static constexpr const char* defaultStatus = "<No file opened>" ;
  static constexpr const char* defaultFileFilter = "Text Files (*.txt *.csv *.xml *.html *.css *.h *.cpp *.cxx *.c *.js)" ;

  QFile file;

  QTextEdit textEdit;
  QMenuBar menuBar;
  QStatusBar statusBar;
  QLabel permanentStatus;

  QMenu topMFile;
  QMenu topMEdit;
  QMenu topMHelp;

  QAction fileNew;
  QAction fileOpen;
  QAction fileSave;
  QAction fileSaveAs;
  QAction fileClose;

  QAction editCopy;
  QAction editCut;
  QAction editPaste;

  QAction helpAbout;

  void entitleMenus();
  void packMenus () ;
  void connectMenus();

};

#endif //QT1SIMPLETEXTEDITORDEMO_EDITORWINDOW_H
