/***************************************************************************
AQTranslator.h
-------------------
begin                : 07/08/2007
copyright            : (C) 2003-2007 by InfoSiAL S.L.
email                : mail@infosial.com
***************************************************************************/
/***************************************************************************
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; version 2 of the License.               *
 ***************************************************************************/
/***************************************************************************
   Este  programa es software libre. Puede redistribuirlo y/o modificarlo
   bajo  los  términos  de  la  Licencia  Pública General de GNU   en  su
   versión 2, publicada  por  la  Free  Software Foundation.
 ***************************************************************************/

#ifndef AQTRANSLATOR_H_
#define AQTRANSLATOR_H_

#include <QTranslator>
#include <QString>

class AQTranslator : public QTranslator
{
public:

  /**
  constructor
  */
  AQTranslator( QObject * parent = 0 );

  /**
  Carga en el traductor el contenido de un fichero de traducciones existente en la caché de disco

  El fichero debe introducirse en la caché de disco antes de llamar a este método, en
  caso contrario no se hará nada.

  @param  key Clave que identifica al fichero en la caché de disco
  @return TRUE si la operación tuvo éxito
  */
  bool loadTsContent( const QString & key );
};

#endif /*AQTRANSLATOR_H_*/
