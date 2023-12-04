/*
 * Copyright (c) 2023, Yurii Sydor (yuriysydor1991@gmail.com) kytok.org.ua
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 *     Redistributions of source code must retain the above copyright notice,
 *     this list of conditions and the following disclaimer.
 *     Redistributions in binary form must reproduce the above copyright notice,
 *     this list of conditions and the following disclaimer in the documentation
 *     and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
 * LIABLE FOR  ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES  (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON  ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT  (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS  SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

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
