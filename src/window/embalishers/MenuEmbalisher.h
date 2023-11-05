//
// Created by cc on 05.11.23.
//

#ifndef QT1SIMPLETEXTEDITORDEMO_MENUEMBALISHER_H
#define QT1SIMPLETEXTEDITORDEMO_MENUEMBALISHER_H

#include <QMainWindow>
#include <QMenuBar>
#include <QAction>
#include <QMenu>
#include <QString>

class MenuEmbalisher {
public:

  MenuEmbalisher (QMainWindow& main) ;

  QAction& getFileNew() ;
  QAction& getFileOpen() ;
  QAction& getFileClose() ;
  QAction& getFileSave() ;
  QAction& getFileSaveAs() ;

private:

  QMainWindow& window ;

  void entitleMenus();
  void packMenus () ;

  QMenuBar menuBar;

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

};


#endif //QT1SIMPLETEXTEDITORDEMO_MENUEMBALISHER_H
