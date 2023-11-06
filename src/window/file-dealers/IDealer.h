//
// Created by cc on 05.11.23.
//

#ifndef QT1SIMPLETEXTEDITORDEMO_IDEALER_H
#define QT1SIMPLETEXTEDITORDEMO_IDEALER_H

#include <QString>

class IDealer {
 public:
  IDealer() = default;

  virtual ~IDealer() = default;

  // true on success,
  // on a failure - everything else
  virtual bool openFile(const QString& path) = 0;

  virtual bool newFile() = 0;

  virtual bool openFile() = 0;

  virtual bool saveFile() = 0;

  virtual bool saveFileAs() = 0;

  virtual bool saveFileAs(const QString& path) = 0;

  virtual bool clear() = 0;

  virtual bool isOpen() = 0;

  virtual QString filename() = 0;
};

#endif  // QT1SIMPLETEXTEDITORDEMO_IDEALER_H
