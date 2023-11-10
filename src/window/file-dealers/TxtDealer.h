//
// Created by cc on 05.11.23.
//

#ifndef QT1SIMPLETEXTEDITORDEMO_TXTDEALER_H
#define QT1SIMPLETEXTEDITORDEMO_TXTDEALER_H

#include <QFile>

#include "IDealer.h"
#include "IEditorWindow.h"

class TxtDealer : public IDealer {
 public:
  explicit TxtDealer(IEditorWindow& main);

  virtual bool openFile(const QString& path) override;

  virtual bool newFile() override;

  virtual bool openFile() override;

  virtual bool saveFile() override;

  virtual bool saveFileAs() override;

  virtual bool saveFileAs(const QString& path) override;

  virtual bool clear() override;

  virtual bool isOpen() override;

  virtual QString filename() override;

 protected:
  IEditorWindow& window;

 private:
  QFile file;

  bool hideOpen(const QString& path);
};

#endif  // QT1SIMPLETEXTEDITORDEMO_TXTDEALER_H
