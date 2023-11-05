//
// Created by cc on 05.11.23.
//

#ifndef QT1SIMPLETEXTEDITORDEMO_MENUEMBELLISHER_H
#define QT1SIMPLETEXTEDITORDEMO_MENUEMBELLISHER_H

#include <QMenuBar>
#include <QAction>
#include <QMenu>
#include <QString>

#include "IEditorWindow.h"

class MenuEmbellisher {
public:

  MenuEmbellisher(IEditorWindow &main);

  QAction &getFileNew();

  QAction &getFileOpen();

  QAction &getFileClose();

  QAction &getFileSave();

  QAction &getFileSaveAs();

private:

  IEditorWindow &window;

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

  void entitleMenus();

  void packMenus();

};


#endif //QT1SIMPLETEXTEDITORDEMO_MENUEMBELLISHER_H
