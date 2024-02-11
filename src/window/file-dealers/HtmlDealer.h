/*
 * Copyright (c) 2023, 2024 Yurii Sydor (yuriysydor1991@gmail.com) kytok.org.ua
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

#ifndef QT1SIMPLETEXTEDITORDEMO_HTMLDEALER_H
#define QT1SIMPLETEXTEDITORDEMO_HTMLDEALER_H

#include <QMenu>
#include <QObject>
#include <QTextEdit>

#include "IEditorWindow.h"
#include "TxtDealer.h"

namespace qt5simpleted22 {

/**
 * HTMLDealer class designed for additional functions
 * for the HTML files. Creates a HTML submenu in
 * the Edit top level menu to declare it's operations.
 *
 * Is descendant of the TxtDealer class, hence supports
 * all the methods of a IDealer abstract class.
 */
class HtmlDealer : public QObject, public TxtDealer {
  Q_OBJECT

 public:
  explicit HtmlDealer(IEditorWindow &main);

  ~HtmlDealer();

  /**
   * Examine given file extension and return a true value
   * if it is one of the well known HTML files extensions.
   * @param ext the file extension
   * @return a true value if given extension is for the HTML file.
   */
  static bool isHtml(const QString &ext);

 private:
  inline static const std::vector<QString> HTML_EXTs{"html", "htm", "xhtml",
                                                     "xhtm"};

  /**
   * The QMenu object that will be appended into
   * Edit menu as a submenu. So the user can
   * perform some HTML operations on the data.
   */
  QMenu subHtml;

  /**
   * The QMenu object that will be appended into
   * subHtml menu as a submenu. So the user can
   * perform HTML <hN>-tags wrapping of the
   * selected text.
   */
  QMenu subHeaders;

  /**
   * Link for a main window text edit widget for convenience.
   */
  QTextEdit &textEdit;

  /**
   * HTML operations menu builder for a subHtml QMenu instance.
   * Creates appropriate actions, sets their title and binds
   * appropriate shortcuts.
   */
  void buildHtmlMenu();

  /**
   * Wraps selected text in textEdit widget, if any, with a
   * given strings (supposingly for the HTML tags). For use
   * with all the wrappers private methods.
   * @param beforeWrap Text which be inserted before selected text.
   * @param afterWrap Text that will be inserted after the
   * selected text.
   * @return Returns true on success. Anything else
   * in case of a failure.
   */
  bool wrapSelectionWith(const QString &beforeWrap, const QString &afterWrap);

 private slots:

  /**
   * Wraps selected by the user text with a <b> tag.
   */
  void wrapB();

  /**
   * Wraps selected by the user text with a <i> tag.
   */
  void wrapI();

  /**
   * Wraps selected by the user text with a <u> tag.
   */
  void wrapU();

  /**
   * Wraps selected by the user text with a link tag.
   */
  void wrapA();

  /**
   * Wraps selected by the user text with a paragraph <p> tag.
   */
  void wrapP();

  /**
   * Wraps selected by the user text with a header <h1> tag.
   */
  void wrapH1();

  /**
   * Wraps selected by the user text with a header <h2> tag.
   */
  void wrapH2();

  /**
   * Wraps selected by the user text with a header <h3> tag.
   */
  void wrapH3();

  /**
   * Wraps selected by the user text with a header <h4> tag.
   */
  void wrapH4();

  /**
   * Wraps selected by the user text with a header <h5> tag.
   */
  void wrapH5();

  /**
   * Wraps selected by the user text with a header <h6> tag.
   */
  void wrapH6();

  /**
   * Wraps selected by the user text with a <pre> tag.
   */
  void wrapPre();

 private:
  constexpr static const char *const classname = "HtmlDealer";
};

}  // namespace qt5simpleted22

#endif  // QT1SIMPLETEXTEDITORDEMO_HTMLDEALER_H
