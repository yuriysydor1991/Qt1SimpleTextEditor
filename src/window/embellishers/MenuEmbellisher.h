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
  QAction& getHelpAboutQt();

  QAction& getEditFind();
  QAction& getEditFindBack();

  QAction& getEditGoTo();

  void addToEdit(QMenu& newMenu);
  void removeFromEdit(QMenu& newMenu);

 private:
  IEditorWindow& window;

  QMenuBar menuBar;

  QMenu topMFile;
  QMenu topMFind;
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
  QAction helpAboutQt;

 private:
  constexpr static const char* const classname = "MenuEmbellisher";

  void entitleMenus();

  void packMenus();

  void setMenusShortCuts();
};

#endif  // QT1SIMPLETEXTEDITORDEMO_MENUEMBELLISHER_H
