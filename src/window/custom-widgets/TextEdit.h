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

#ifndef QT1SIMPLETEXTEDITORDEMO_TEXTEDIT_H
#define QT1SIMPLETEXTEDITORDEMO_TEXTEDIT_H

#include <QMimeData>
#include <QTextEdit>

/**
 * Class designed to redefine some
 * of the default behaviour of the
 * standard QTextEdit object.
 *
 * For example, by default you can paste
 * formatted text into the QTextEdit widget
 * which is not expected behaviour of the
 * simple text editor.
 */
class TextEdit : public QTextEdit {
 public:
  TextEdit() = default;
  ~TextEdit() = default;

 protected:
  /**
   * Overridden standard method for a clipboard
   * insertion, which prevents of inserting
   * text with formatting and embellishments, e.g.
   * bolded text, bigger font size, another
   * color, which regular text formats are not
   * supporting directly.
   * @param source QtMimeData as source of a clipboard
   * data.
   */
  virtual void insertFromMimeData(const QMimeData *source) override;
};

#endif  // QT1SIMPLETEXTEDITORDEMO_TEXTEDIT_H
