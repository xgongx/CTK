/*=============================================================================

  Library: CTK

  Copyright (c) 2010 German Cancer Research Center,
    Division of Medical and Biological Informatics

  Licensed under the Apache License, Version 2.0 (the "License");
  you may not use this file except in compliance with the License.
  You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

  Unless required by applicable law or agreed to in writing, software
  distributed under the License is distributed on an "AS IS" BASIS,
  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  See the License for the specific language governing permissions and
  limitations under the License.

=============================================================================*/


#ifndef CTKDICOMHOSTSERVERPRIVATE_H
#define CTKDICOMHOSTSERVERPRIVATE_H

#include <QObject>
#include <QtSoapMessage>

#include <ctkSimpleSoapServer.h>

class ctkDicomHostInterface;

class ctkDicomHostServerPrivate : public QObject
{
  Q_OBJECT

public:
  ctkDicomHostServerPrivate(QObject *parent = 0);

  ctkSimpleSoapServer server;

public slots:

  void incomingSoapMessage(const QtSoapMessage& message,
                           QtSoapMessage* reply);

private:

  void processGetAvailableScreen(const QtSoapMessage& message,
                                 QtSoapMessage* reply);
  void processNotifyStateChanged(const QtSoapMessage& message,
                                 QtSoapMessage* reply);
  void processNotifyStatus(const QtSoapMessage& message,
                                 QtSoapMessage* reply);
  //void processGenerateUID(const QtSoapMessage& message,
  //                               QtSoapMessage* reply);

  ctkDicomHostInterface* serviceBinding;

};

#endif // CTKDICOMHOSTSERVERPRIVATE_H
