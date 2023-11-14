//
// Created by cc on 05.11.23.
//

#ifndef QT1SIMPLETEXTEDITORDEMO_MENUEMBELLISHER_H
#define QT1SIMPLETEXTEDITORDEMO_MENUEMBELLISHER_H

#include <QAction>
#include <QMenu>
#include <QMenuBar>

#include "IEditorWindow.h"

/**
 * Class that handles menu building for
 * the editor application main window
 * instance, e.g. the EditorWindow class object.
 *
 * Holds instances of the all available well
 * known editor operations in form o QAction
 * and other class objects.
 */
class MenuEmbellisher {
 public:
  explicit MenuEmbellisher(IEditorWindow& main);

  /**
   * Returns the fileNew QAction instance which is
   * packed into the File top level menu.
   * @return Returns a reference to the fileNew
   * QAction instance.
   */
  QAction& getFileNew();

  /**
   * Returns the fileOpen QAction instance which is
   * packed into the File top level menu.
   * @return Returns a reference to the fileOpen
   * QAction instance.
   */
  QAction& getFileOpen();

  /**
   * Returns the fileClose QAction instance which is
   * packed into the File top level menu.
   * @return Returns a reference to the fileClose
   * QAction instance.
   */
  QAction& getFileClose();

  /**
   * Returns the fileSave QAction instance which is
   * packed into the File top level menu.
   * @return Returns a reference to the fileSave
   * QAction instance.
   */
  QAction& getFileSave();

  /**
   * Returns the fileSaveAs QAction instance which is
   * packed into the File top level menu.
   * @return Returns a reference to the fileSaveAs
   * QAction instance.
   */
  QAction& getFileSaveAs();

  /**
   * Returns the editCopy QAction instance which is
   * packed into the Edit top level menu.
   * @return Returns a reference to the editCopy
   * QAction instance.
   */
  QAction& getEditCopy();

  /**
   * Returns the editCut QAction instance which is
   * packed into the Edit top level menu.
   * @return Returns a reference to the editCut
   * QAction instance.
   */
  QAction& getEditCut();

  /**
   * Returns the editPaste QAction instance which is
   * packed into the Edit top level menu.
   * @return Returns a reference to the editPaste
   * QAction instance.
   */
  QAction& getEditPaste();

  /**
   * Returns the editUndo QAction instance which is
   * packed into the Edit top level menu.
   * @return Returns a reference to the editUndo
   * QAction instance.
   */
  QAction& getEditUndo();

  /**
   * Returns the editRedo QAction instance which is
   * packed into the Edit top level menu.
   * @return Returns a reference to the editRedo
   * QAction instance.
   */
  QAction& getEditRedo();

  /**
   * Returns the helpAbout QAction instance which is
   * packed into the Help top level menu.
   * @return Returns a reference to the helpAbout
   * QAction instance.
   */
  QAction& getHelpAbout();

  /**
   * Returns the helpAboutQt QAction instance which is
   * packed into the Help top level menu.
   * @return Returns a reference to the helpAboutQt
   * QAction instance.
   */
  QAction& getHelpAboutQt();

  /**
   * Returns the editFimd QAction instance which is
   * packed into the Search top level menu.
   * @return Returns a reference to the editFimd
   * QAction instance.
   */
  QAction& getEditFind();

  /**
   * Returns the editFimdBackwards QAction instance which is
   * packed into the Search top level menu.
   * @return Returns a reference to the editFimdBackwards
   * QAction instance.
   */
  QAction& getEditFindBack();

  /**
   * Returns the editGoTo QAction instance which is
   * packed into the Search top level menu.
   * @return Returns a reference to the editGoTo
   * QAction instance.
   */
  QAction& getEditGoTo();

  /**
   * Adds a given menu instance into
   * the Edit top level menu. Used by
   * particular file dealers (descendants
   * of a IDealer abstract class) to declare
   * new additional file operations.
   *
   * The EditorWindow class uses this method
   * to delegate it's execution.
   * @param newMenu QMenu instance with
   * prepared QActions to add to the
   * Edit top level menu.
   */
  void addToEdit(QMenu& newMenu);

  /**
   * Removes previously inserted by the addToEdit()
   * method QMenu object. Usualy should be used
   * in the destructor of a particular file dealer
   * (IDealer class descendant).
   *
   * @param newMenu The QMenu instance that should be
   * removed from the Edit top level menu.
   */
  void removeFromEdit(QMenu& newMenu);

 private:
  /**
   * Main window reference to perform
   * actions on.
   */
  IEditorWindow& window;

  /**
   * Main menu bar that eventually, after all
   * executed menu building operations, will
   * be provided for the window instance by
   * setMainMenu() method.
   */
  QMenuBar menuBar;

  /**
   * The top level File menu QAction instance.
   */
  QMenu topMFile;
  /**
   * The top level Find or Search menu QAction instance.
   */
  QMenu topMFind;
  /**
   * The top level Edit menu QAction instance.
   */
  QMenu topMEdit;
  /**
   * The top level Help menu QAction instance.
   */
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

  /**
   * Gives titles to all the QMenu and QAction
   * instances.
   */
  void entitleMenus();

  /**
   * Packs all the menu items into the
   * top level menus and inserts
   * the top level menus into a QMenuBar
   * object.
   */
  void packMenus();

  /**
   * Binds appropriate shortcuts into
   * available actions for a quick
   * operations call.
   */
  void setMenusShortCuts();
};

#endif  // QT1SIMPLETEXTEDITORDEMO_MENUEMBELLISHER_H
