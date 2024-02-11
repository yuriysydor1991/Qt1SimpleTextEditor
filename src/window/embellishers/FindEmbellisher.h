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

#ifndef QT1SIMPLETEXTEDITORDEMO_FINDEMBELLISHER_H
#define QT1SIMPLETEXTEDITORDEMO_FINDEMBELLISHER_H

#include <QString>

#include "IEditorWindow.h"

namespace qt5simpleted22 {

/**
 * Class encapsulates text search operations
 * to be used by the EditorWindow class instance
 * which delegates search commands to this class
 * object.
 */
class FindEmbellisher {
 public:
  explicit FindEmbellisher(IEditorWindow &main);

  /**
   * Shows the search window. Search direction is performed
   * in accordance of a given paramenter.
   * @param backwards If set to true search will be performed
   * in the backwards direction. Search dialog title
   * will be set appropriately.
   */
  void show(bool backwards = false);

 private:
  constexpr static const char *const classname = "FindEmbellisher";

  /**
   * The main editor window instance refenrece.
   */
  IEditorWindow &window;

  /**
   * QString instance to store previously entered
   * search text. Used to set the value of a
   * search dialog's input field for a quick
   * repetition search.
   */
  QString text;
};

}  // namespace qt5simpleted22

#endif  // QT1SIMPLETEXTEDITORDEMO_FINDEMBELLISHER_H
