//
// Created by cc on 05.11.23.
//

#ifndef QT1SIMPLETEXTEDITORDEMO_MENUEMBELLISHER_H
#define QT1SIMPLETEXTEDITORDEMO_MENUEMBELLISHER_H

#include <QAction>
#include <QMenu>
#include <QMenuBar>
#include <QString>

#include "IEditorWindow.h"

class MenuEmbellisher {
 public:
  explicit MenuEmbellisher(IEditorWindow& main);

  QAction& getFileNew();

  QAction& getFileOpen();

  QAction& getFileClose();

  QAction& getFileSave();

  QAction& getFileSaveAs();

  QAction& getEditCopy();

  QAction& getEditCut();

  QAction& getEditPaste();

  QAction& getEditUndo();

  QAction& getEditRedo();

  QAction& getHelpAbout();

  QAction& getEditFind();
  QAction& getEditFindBack();

  QAction& getEditGoTo();

 private:
  IEditorWindow& window;

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
  QAction editUndo;
  QAction editRedo;
  QAction editFind;
  QAction editFindBack;
  QAction editGoTo;

  QAction helpAbout;

 private:
  void entitleMenus();

  void packMenus();

  void setMenusShortCuts();
};

#endif  // QT1SIMPLETEXTEDITORDEMO_MENUEMBELLISHER_H
