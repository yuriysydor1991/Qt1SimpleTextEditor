//
// Created by cc on 16.11.23.
//

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
