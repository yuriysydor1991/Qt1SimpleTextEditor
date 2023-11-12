//
// Created by cc on 10.11.23.
//

#ifndef QT1SIMPLETEXTEDITORDEMO_HTMLDEALER_H
#define QT1SIMPLETEXTEDITORDEMO_HTMLDEALER_H

#include <QMenu>
#include <QObject>
#include <QTextEdit>

#include "IEditorWindow.h"
#include "TxtDealer.h"

class HtmlDealer : public QObject, public TxtDealer {
  Q_OBJECT

 public:
  explicit HtmlDealer(IEditorWindow& main);
  ~HtmlDealer();

  static bool isHtml(const QString& ext);

 private:
  inline static const std::vector<QString> HTML_EXTs{"html", "htm", "xhtml",
                                                     "xhtm"};

  QMenu subHtml;
  QTextEdit& textEdit;

  void buildHtmlMenu();

  bool wrapSelectionWith(const QString& beforeWrap, const QString& afterWrap);

 private slots:
  void wrapB();
  void wrapI();
  void wrapU();

  void wrapA();

  void wrapH1();
  void wrapH2();
  void wrapH3();
  void wrapH4();
  void wrapH5();
  void wrapH6();
};

#endif  // QT1SIMPLETEXTEDITORDEMO_HTMLDEALER_H
