/***************************************************************************
                            FLSmtpClient.h
                          -------------------
 begin                : vie dic 1 2006
 copyright            : (C) 2006 by InfoSiAL S.L.
 email                : mail@infosial.com
***************************************************************************/
/***************************************************************************
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; version 2 of the License.               *
 ***************************************************************************/
/***************************************************************************
   Este  programa es software libre. Puede redistribuirlo y/o modificarlo
   bajo  los  t�rminos  de  la  Licencia  P�blica General de GNU   en  su
   versi�n 2, publicada  por  la  Free  Software Foundation.
 ***************************************************************************/

#ifndef FLSMTPCLIENT_H
#define FLSMTPCLIENT_H

#include <qobject.h>
#include <qstringlist.h>
#include <qmime.h>
#include <qfile.h>
#include <qfileinfo.h>
#include <qapplication.h>
#include <qmessagebox.h>
#include <qpixmap.h>

/**
Cliente SMTP para correo electr�nico

Esta clase es utilizada para componer un mensaje de correo electr�nico y
enviarlo mediante el protocolo SMTP.

@author InfoSiAL, S.L.
*/
class FL_EXPORT FLSmtpClient : public QObject {

  Q_OBJECT

public:

  /**
  constructor
  */
  FLSmtpClient( QObject * parent = 0 );

  /**
  destructor
  */
  ~FLSmtpClient();

  /**
  Establece el remitente del mensaje

  @param from Direcci�n de correo del remitente
  */
  void setFrom( const QString & from );

  /**
  Establece el destinatario del mensaje

  @param to Direcci�n de correo del destinatario
  */
  void setTo( const QString & to );

  /**
  Establece el asunto del mensaje

  @param subject Texto del asunto
  */
  void setSubject( const QString & subject );

  /**
  Establece el cuerpo del mensaje

  @param body Texto del cuerpo
  */
  void setBody( const QString & body );

  /**
  Adjunta un fichero al mensaje

  @param attach Ruta y nombre del fichero a adjuntar
  @param cid    Id para incrustar fichero en HTML
  */
  void addAttachment( const QString & attach, const QString & cid = QString::null );

  /**
  A�ade una parte de texto al mensaje

  @param text     Texto a a�adir
  @param mimeType Formato MIME del texto. Por defecto text/plain
  */
  void addTextPart( const QString & text, const QString & mimeType = "text/plain");
  
  /**
  Servidor de correo saliente.

  Si no se indica un servidor de correo saliente intentar� averiguarlo
  mediante los registros MX de los servidores de DNS.

  @param mS Nombre o direccion IP del servidor de correo saliente
  */
  void setMailServer( const QString & mS );
  
  /**
  Formato MIME del cuerpo del mensaje

  @param mT Nombre del formato
  */
  void setMimeType( const QString & mT );

public slots:

  /**
  Inicia el env�o del mensaje
  */
  void startSend();

signals:

  /**
  Informa del estado del env�o
  */
  void status( const QString & );

  /**
  Indica que se ha iniciado el env�o del mensaje
  */
  void sendStarted();

  /**
  Indica que se ha finalizado el env�o del mensaje
  */
  void sendEnded();

  /**
  Indica los pasos totales que se ejecutar�n en el proceso de env�o. Usado para di�logos de progreso.
  */
  void sendTotalSteps( int );

  /**
  Indica el n�mero de paso que se van a ejecutar. Usado para di�logos de progreso.
  */
  void sendStepNumber( int );

protected:

  /**
  Mantiene la f�brica de fuentes MIME para ficheros
  */
  static QMimeSourceFactory * mimeSourceFactory_;

  /**
  Crea la f�brica de fuentes MIME para ficheros
  */
  static QMimeSourceFactory * mimeSourceFactory();

private:

  /**
  Remitente del mensaje
  */
  QString from_;

  /**
  Destinatario del mensaje
  */
  QString to_;

  /**
  Asunto del mensaje
  */
  QString subject_;

  /**
  Cuerpo del mensaje
  */
  QString body_;

  /**
  Lista de rutas y nombres de ficheros adjuntos
  */
  QStringList attachments_;

  /**
  Mapa de adjuntos con sus identificadores
  */
  QMap<QString, QString> mapAttachCid_;
  
  /**
  Servidor de correo saliente
  */
  QString mailServer_;
  
  /**
  Formato MIME
  */
  QString mimeType_;

  /**
  Lista de partes de texto
  */
  QStringList textParts_;
};

#endif
