//
// Created by cc on 08.11.23.
//

#ifndef QT1SIMPLETEXTEDITORDEMO_GOTOLINEEMBELLISHER_H
#define QT1SIMPLETEXTEDITORDEMO_GOTOLINEEMBELLISHER_H

#include "IEditorWindow.h"

/**
 * Class for dealing with showing
 * a dialog to enter the line number
 * and scroll to the appropriate line
 * in main editor widget.
 */
class GoToLineEmbellisher {
 public:
  explicit GoToLineEmbellisher(IEditorWindow& main);

  /**
   * Show the go to line dialog, which allows
   * the user to enter line number in range of the
   * available lines.
   */
  void show_goto();

 private:
  constexpr static const char* const classname = "GoToLineEmbellisher";

  /**
   * Main editor window instance to perform
   * go to line operations on.
   */
  IEditorWindow& window;

  /**
   * Contant to search and count of the
   * available lines in the editor window.
   */
  constexpr static const char NLINE = '\n';

  /**
   * Search for the line specified in the
   * go to line dialog.
   * @param edit Edit widget from the main window.
   * @param text The contents of a EditorWindow editor widget
   * @param cline Line to scroll to.
   */
  void searchAndSet(QTextEdit& edit, const QString& text,
                    const qsizetype cline);

  /**
   * Sets the cursor at chosen location and ensures
   * that it is visible by the user.
   * @param edit Main text edit widget of the text editor
   * application.
   * @param pos Position index to be set.
   */
  void setCursor(QTextEdit& edit, const qsizetype pos);
};

#endif  // QT1SIMPLETEXTEDITORDEMO_GOTOLINEEMBELLISHER_H
