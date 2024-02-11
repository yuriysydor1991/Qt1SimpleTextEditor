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

#ifndef QT1SIMPLETEXTEDITORDEMO_TXTDEALER_H
#define QT1SIMPLETEXTEDITORDEMO_TXTDEALER_H

#include <QFile>

#include "IDealer.h"
#include "IEditorWindow.h"

namespace qt5simpleted22 {

/**
 * Class that encapsulates code that
 * deals with raw file operations and
 * stores the QFile instance that
 * represents opened file.
 */
class TxtDealer : public IDealer {
 public:
  explicit TxtDealer(IEditorWindow &main);

  virtual bool openFile(const QString &path) override;

  virtual bool newFile() override;

  virtual bool openFile() override;

  virtual bool saveFile() override;

  virtual bool saveFileAs() override;

  virtual bool saveFileAs(const QString &path) override;

  virtual bool clear() override;

  virtual bool isOpen() override;

  virtual QString filename() override;

 protected:
  IEditorWindow &window;

 private:
  constexpr static const char *const classname = "TxtDealer";

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
  bool hideOpen(const QString &path);
};

}  // namespace qt5simpleted22

#endif  // QT1SIMPLETEXTEDITORDEMO_TXTDEALER_H
