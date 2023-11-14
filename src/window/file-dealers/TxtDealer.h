//
// Created by cc on 05.11.23.
//

#ifndef QT1SIMPLETEXTEDITORDEMO_TXTDEALER_H
#define QT1SIMPLETEXTEDITORDEMO_TXTDEALER_H

#include <QFile>

#include "IDealer.h"
#include "IEditorWindow.h"

/**
 * Class that encapsulates code that
 * deals with raw file operations and
 * stores the QFile instance that
 * represents opened file.
 */
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
  constexpr static const char* const classname = "TxtDealer";

  /**
   * Instance that platform independently deals with
   * the file storage.
   */
  QFile file;

  /**
   * Method that encapsulates file opening routine.
   * @param path Path to the file to be opened.
   * @return Returns true if file was successfully
   * opened and any other value in case of a failure.
   */
  bool hideOpen(const QString& path);
};

#endif  // QT1SIMPLETEXTEDITORDEMO_TXTDEALER_H
