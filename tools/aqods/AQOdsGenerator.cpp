/***************************************************************************
 AQOdsGenerator.cpp
 -------------------
 begin                : 16/12/2011
 copyright            : (C) 2003-2011 by InfoSiAL S.L.
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

#include "AQOdsGenerator.h"
#include "AQS_p.h"
#include "AQZipWriter.h"

static char data_main[] = {
  105, 99, 74, 101, 69, 87, 69, 76, 66, 103, 50, 80, 77, 80, 112, 57, 86, 78, 66, 119,
  57, 101, 115, 76, 50, 84, 75, 81, 90, 53, 74, 81, 56, 122, 83, 115, 49, 107, 50, 90,
  108, 110, 104, 106, 122, 75, 73, 105, 110, 103, 52, 87, 107, 66, 80, 105, 121, 79, 56, 89,
  116, 68, 75, 107, 84, 71, 112, 105, 68, 80, 99, 43, 112, 43, 117, 100, 119, 84, 55, 98,
  43, 119, 66, 84, 97, 67, 112, 105, 98, 106, 121, 65, 53, 105, 85, 85, 75, 73, 87, 80,
  97, 105, 112, 71, 120, 119, 68, 82, 89, 104, 54, 50, 85, 79, 112, 81, 84, 105, 103, 71,
  52, 85, 50, 65, 54, 109, 67, 76, 47, 50, 74, 102, 65, 80, 47, 83, 86, 122, 90, 122,
  80, 71, 112, 51, 79, 119, 109, 100, 67, 55, 112, 82, 100, 98, 82, 97, 108, 69, 111, 118,
  81, 51, 43, 47, 100, 71, 49, 97, 102, 97, 80, 74, 99, 54, 110, 48, 107, 111, 111, 106,
  70, 111, 66, 48, 120, 68, 52, 120, 114, 81, 83, 52, 109, 113, 106, 78, 65, 48, 100, 88,
  116, 75, 88, 101, 48, 43, 52, 53, 112, 112, 74, 80, 84, 120, 66, 78, 75, 97, 57, 83,
  72, 49, 109, 118, 78, 78, 77, 116, 81, 100, 112, 57, 50, 102, 54, 86, 85, 88, 79, 57,
  54, 97, 68, 87, 51, 113, 107, 48, 49, 84, 80, 82, 77, 47, 98, 50, 79, 65, 77, 113,
  56, 120, 81, 113, 80, 108, 65, 87, 71, 74, 97, 100, 67, 122, 83, 114, 104, 112, 49, 77,
  73, 108, 89, 114, 53, 80, 110, 100, 102, 105, 79, 119, 72, 76, 107, 72, 112, 110, 83, 117,
  43, 70, 53, 69, 106, 84, 87, 100, 104, 101, 120, 52, 66, 110, 115, 122, 113, 50, 54, 52,
  68, 80, 80, 48, 67, 47, 55, 110, 117, 66, 108, 89, 121, 76, 82, 84, 55, 82, 106, 65,
  117, 89, 101, 71, 98, 85, 43, 67, 108, 108, 103, 86, 76, 66, 78, 77, 108, 70, 57, 113,
  71, 111, 107, 52, 85, 74, 73, 43, 120, 79, 118, 78, 69, 87, 66, 119, 53, 81, 82, 51,
  82, 54, 78, 105, 90, 75, 70, 110, 118, 80, 114, 83, 84, 43, 100, 89, 89, 112, 110, 101,
  100, 79, 110, 98, 48, 50, 87, 70, 69, 84, 83, 102, 90, 47, 53, 84, 108, 111, 80, 110,
  101, 117, 120, 98, 55, 75, 76, 78, 51, 109, 57, 68, 86, 72, 83, 69, 110, 114, 70, 43,
  89, 102, 113, 69, 98, 121, 75, 65, 112, 73, 111, 120, 54, 97, 69, 88, 122, 82, 105, 101,
  115, 109, 56, 80, 114, 51, 106, 48, 114, 56, 109, 101, 109, 84, 107, 115, 84, 120, 119, 65,
  43, 73, 100, 47, 103, 66, 68, 97, 115, 78, 86, 67, 118, 99, 111, 71, 72, 117, 97, 75,
  110, 52, 119, 86, 119, 118, 50, 80, 65, 71, 121, 97, 70, 55, 57, 117, 108, 104, 50, 72,
  56, 121, 81, 111, 69, 113, 51, 53, 66, 98, 52, 86, 86, 102, 75, 84, 110, 78, 69, 69,
  76, 88, 99, 51, 117, 74, 67, 86, 67, 109, 122, 49, 97, 120, 105, 111, 43, 72, 98, 56,
  108, 103, 98, 54, 107, 122, 104, 85, 81, 107, 65, 69, 75, 73, 82, 87, 111, 54, 47, 119,
  110, 48, 104, 87, 75, 100, 85, 120, 55, 90, 121, 53, 67, 119, 111, 108, 47, 69, 74, 110,
  55, 99, 72, 80, 53, 47, 84, 55, 121, 56, 110, 111, 50, 57, 68, 118, 82, 98, 57, 118,
  115, 70, 53, 71, 107, 71, 43, 117, 99, 113, 83, 107, 120, 110, 106, 69, 88, 115, 119, 108,
  106, 77, 71, 70, 107, 107, 87, 115, 120, 83, 80, 50, 97, 112, 81, 121, 78, 75, 119, 70,
  102, 47, 113, 74, 71, 112, 97, 121, 104, 85, 55, 98, 65, 52, 110, 78, 97, 75, 74, 103,
  90, 52, 72, 83, 84, 104, 49, 105, 66, 74, 77, 116, 115, 56, 50, 70, 75, 100, 80, 114,
  97, 99, 118, 55, 86, 82, 70, 108, 90, 99, 77, 107, 103, 54, 106, 71, 105, 120, 118, 70,
  101, 107, 88, 100, 77, 122, 100, 120, 65, 109, 49, 87, 118, 82, 119, 108, 122, 104, 112, 100,
  115, 90, 69, 85, 54, 81, 88, 70, 108, 73, 84, 85, 83, 117, 72, 51, 71, 55, 104, 117,
  102, 119, 47, 54, 116, 97, 65, 104, 100, 76, 121, 105, 109, 48, 79, 115, 43, 52, 52, 43,
  112, 109, 52, 98, 85, 86, 117, 109, 75, 53, 43, 117, 90, 98, 49, 113, 75, 70, 117, 122,
  68, 81, 87, 86, 48, 65, 81, 77, 78, 115, 102, 50, 116, 122, 108, 102, 100, 115, 88, 78,
  89, 121, 83, 70, 90, 83, 87, 66, 89, 80, 102, 103, 103, 88, 66, 76, 84, 118, 122, 84,
  55, 88, 110, 86, 79, 77, 99, 77, 83, 111, 83, 68, 101, 122, 99, 121, 71, 73, 43, 47,
  105, 80, 68, 117, 106, 106, 79, 87, 122, 122, 70, 68, 77, 53, 116, 105, 118, 100, 105, 97,
  112, 47, 100, 51, 74, 88, 79, 109, 107, 54, 79, 116, 89, 121, 99, 81, 66, 54, 71, 70,
  51, 82, 120, 50, 48, 118, 79, 106, 48, 83, 105, 112, 115, 78, 55, 116, 57, 102, 52, 48,
  115, 118, 85, 82, 107, 88, 50, 80, 55, 104, 100, 55, 77, 107, 117, 99, 77, 117, 122, 100,
  87, 97, 77, 111, 66, 113, 103, 49, 78, 90, 56, 117, 101, 106, 103, 47, 82, 104, 89, 75,
  121, 72, 84, 120, 78, 118, 75, 67, 102, 65, 52, 66, 119, 72, 82, 75, 50, 54, 88, 106,
  116, 43, 103, 78, 55, 119, 98, 82, 108, 77, 113, 69, 74, 54, 83, 47, 71, 75, 115, 43,
  87, 70, 69, 115, 90, 83, 47, 105, 56, 89, 101, 75, 82, 99, 43, 68, 120, 89, 51, 82,
  56, 88, 53, 71, 80, 50, 67, 65, 66, 87, 53, 115, 112, 68, 86, 79, 74, 88, 65, 85,
  119, 83, 114, 87, 85, 109, 82, 97, 51, 110, 73, 70, 120, 90, 52, 83, 54, 68, 119, 50,
  76, 78, 53, 105, 55, 86, 81, 50, 52, 67, 112, 111, 99, 103, 87, 49, 111, 109, 80, 103,
  80, 69, 99, 122, 79, 72, 113, 81, 47, 115, 88, 101, 55, 109, 108, 122, 100, 69, 112, 81,
  117, 102, 56, 111, 78, 122, 56, 73, 55, 51, 83, 97, 85, 55, 85, 47, 106, 100, 73, 105,
  113, 107, 87, 72, 99, 109, 67, 117, 118, 105, 79, 68, 119, 70, 77, 84, 98, 65, 103, 54,
  100, 107, 51, 76, 88, 55, 57, 65, 69, 53, 120, 49, 52, 53, 109, 116, 76, 73, 72, 115,
  117, 121, 43, 116, 85, 86, 119, 112, 122, 90, 122, 117, 88, 48, 86, 68, 110, 85, 81, 99,
  113, 122, 109, 121, 43, 49, 112, 102, 122, 47, 120, 88, 83, 47, 118, 73, 66, 105, 89, 68,
  76, 49, 116, 51, 73, 117, 110, 70, 121, 106, 75, 67, 74, 117, 118, 83, 104, 122, 97, 116,
  98, 83, 75, 90, 74, 66, 100, 115, 49, 70, 120, 103, 56, 115, 102, 69, 69, 82, 78, 52,
  74, 116, 57, 88, 98, 52, 90, 74, 81, 49, 80, 69, 57, 107, 121, 79, 120, 97, 88, 122,
  88, 114, 118, 66, 73, 110, 55, 56, 83, 100, 65, 114, 89, 79, 99, 81, 67, 71, 116, 113,
  87, 78, 100, 66, 79, 80, 73, 67, 55, 117, 90, 71, 85, 114, 112, 76, 74, 105, 47, 56,
  105, 81, 82, 81, 54, 56, 104, 113, 111, 89, 68, 100, 108, 47, 48, 105, 65, 106, 99, 116,
  73, 112, 69, 101, 103, 119, 106, 100, 122, 87, 98, 73, 73, 84, 54, 99, 69, 98, 107, 54,
  97, 76, 117, 117, 73, 56, 82, 108, 120, 85, 98, 49, 99, 73, 70, 103, 74, 75, 70, 47,
  81, 79, 68, 43, 48, 89, 90, 84, 74, 87, 115, 90, 86, 47, 77, 76, 49, 110, 89, 56,
  87, 100, 80, 122, 55, 89, 70, 73, 118, 87, 101, 43, 48, 48, 106, 118, 50, 110, 119, 55,
  109, 122, 119, 89, 86, 100, 66, 79, 87, 75, 56, 71, 85, 120, 99, 66, 76, 76, 54, 70,
  73, 85, 51, 75, 89, 71, 56, 79, 49, 82, 55, 73, 116, 73, 76, 100, 104, 100, 89, 116,
  77, 80, 51, 55, 97, 55, 78, 97, 122, 51, 56, 85, 98, 85, 74, 57, 118, 49, 86, 48,
  112, 78, 110, 57, 51, 100, 66, 79, 50, 47, 47, 117, 99, 84, 98, 79, 76, 118, 100, 119,
  107, 57, 110, 100, 71, 108, 81, 114, 53, 82, 66, 100, 119, 86, 103, 89, 76, 50, 102, 120,
  70, 52, 82, 86, 84, 76, 82, 110, 86, 111, 114, 70, 98, 48, 88, 75, 107, 57, 72, 118,
  107, 68, 111, 108, 120, 67, 77, 48, 87, 69, 82, 79, 77, 113, 43, 104, 87, 90, 106, 113,
  81, 119, 48, 115, 52, 89, 74, 98, 104, 73, 103, 66, 78, 110, 121, 49, 97, 106, 69, 102,
  117, 99, 54, 77, 108, 54, 65, 66, 101, 56, 117, 86, 104, 105, 47, 85, 79, 102, 112, 75,
  118, 47, 88, 97, 104, 53, 53, 70, 55, 71, 99, 49, 75, 74, 57, 50, 48, 106, 116, 78,
  115, 98, 112, 118, 74, 111, 89, 86, 88, 65, 53, 104, 55, 75, 99, 102, 108, 111, 70, 116,
  113, 107, 51, 89, 87, 108, 52, 84, 72, 57, 83, 68, 102, 83, 87, 97, 77, 108, 86, 87,
  103, 84, 86, 53, 117, 111, 80, 100, 47, 105, 90, 53, 48, 108, 113, 90, 79, 43, 116, 86,
  65, 122, 84, 50, 99, 87, 88, 111, 99, 78, 81, 82, 117, 116, 112, 97, 109, 118, 56, 73,
  83, 89, 112, 56, 50, 52, 50, 76, 105, 81, 107, 57, 73, 81, 78, 105, 50, 71, 113, 73,
  72, 117, 114, 88, 119, 88, 82, 47, 73, 120, 77, 84, 86, 48, 111, 98, 57, 106, 114, 57,
  116, 55, 110, 85, 69, 55, 79, 107, 82, 102, 71, 109, 121, 74, 107, 68, 100, 110, 76, 65,
  77, 89, 86, 57, 72, 66, 110, 73, 78, 78, 104, 85, 87, 109, 43, 102, 48, 48, 88, 56,
  68, 84, 72, 102, 112, 55, 116, 98, 107, 109, 50, 65, 102, 70, 110, 121, 53, 74, 73, 81,
  55, 84, 120, 86, 104, 106, 98, 121, 99, 90, 111, 116, 55, 71, 87, 74, 88, 114, 89, 69,
  55, 65, 88, 87, 74, 99, 69, 76, 100, 51, 51, 74, 77, 101, 120, 81, 49, 87, 90, 103,
  49, 54, 75, 80, 86, 88, 72, 81, 82, 57, 47, 90, 78, 121, 107, 113, 89, 97, 106, 68,
  109, 52, 116, 101, 122, 104, 86, 117, 109, 47, 83, 57, 88, 103, 50, 110, 73, 79, 112, 110,
  89, 83, 50, 68, 68, 56, 118, 69, 79, 116, 48, 57, 113, 101, 77, 104, 75, 108, 101, 69,
  106, 103, 89, 111, 69, 86, 87, 87, 118, 55, 55, 106, 97, 50, 85, 113, 74, 72, 97, 52,
  50, 72, 100, 47, 84, 115, 84, 73, 78, 54, 122, 105, 122, 86, 56, 103, 48, 74, 49, 66,
  119, 98, 87, 52, 86, 66, 85, 53, 122, 75, 77, 69, 65, 70, 88, 104, 56, 69, 55, 80,
  118, 74, 122, 52, 100, 115, 97, 98, 108, 112, 109, 76, 89, 66, 97, 50, 118, 67, 57, 122,
  115, 98, 120, 90, 83, 106, 97, 110, 82, 120, 109, 70, 86, 112, 97, 69, 86, 90, 122, 57,
  55, 56, 65, 109, 51, 103, 82, 99, 87, 101, 122, 77, 110, 99, 84, 88, 114, 76, 80, 107,
  53, 118, 112, 86, 67, 109, 122, 118, 89, 49, 88, 99, 57, 102, 57, 106, 77, 80, 97, 50,
  116, 65, 57, 122, 117, 102, 97, 52, 66, 122, 85, 121, 77, 43, 97, 100, 57, 77, 98, 79,
  43, 90, 120, 107, 54, 108, 118, 90, 78, 122, 111, 105, 65, 49, 86, 82, 71, 77, 68, 52,
  105, 47, 121, 52, 107, 82, 122, 101, 43, 83, 81, 71, 108, 65, 54, 117, 117, 101, 89, 82,
  74, 107, 108, 83, 74, 82, 86, 81, 100, 75, 73, 120, 81, 119, 90, 101, 78, 120, 47, 112,
  121, 56, 65, 71, 119, 75, 50, 88, 105, 55, 117, 88, 56, 68, 119, 65, 113, 99, 78, 98,
  77, 101, 84, 99, 71, 50, 57, 89, 84, 50, 101, 103, 70, 105, 73, 73, 103, 70, 75, 77,
  43, 54, 53, 82, 107, 115, 112, 84, 97, 108, 115, 85, 84, 76, 51, 68, 80, 102, 98, 101,
  56, 47, 68, 113, 73, 84, 110, 47, 97, 115, 103, 116, 76, 48, 107, 87, 107, 116, 51, 116,
  80, 90, 72, 66, 117, 98, 81, 100, 54, 116, 120, 56, 106, 89, 115, 119, 69, 119, 85, 114,
  84, 71, 114, 73, 72, 43, 54, 85, 47, 75, 110, 66, 56, 105, 70, 113, 99, 80, 121, 81,
  71, 121, 85, 98, 111, 101, 90, 115, 81, 78, 105, 77, 65, 115, 80, 90, 112, 116, 82, 102,
  49, 69, 74, 101, 84, 103, 105, 69, 114, 50, 121, 121, 107, 77, 65, 83, 115, 51, 77, 114,
  117, 66, 86, 104, 113, 76, 110, 82, 99, 87, 109, 121, 43, 103, 110, 75, 43, 122, 111, 98,
  105, 67, 86, 75, 51, 111, 101, 85, 110, 120, 69, 80, 117, 81, 88, 55, 116, 47, 118, 89,
  70, 86, 115, 56, 47, 114, 69, 75, 50, 56, 122, 120, 67, 56, 87, 114, 66, 81, 48, 57,
  51, 98, 81, 121, 82, 72, 97, 114, 105, 107, 116, 100, 115, 70, 57, 114, 52, 121, 71, 48,
  103, 116, 115, 106, 121, 120, 111, 55, 119, 88, 76, 109, 106, 85, 84, 68, 43, 76, 108, 100,
  69, 122, 67, 107, 111, 54, 72, 102, 98, 73, 70, 83, 47, 115, 71, 103, 108, 74, 122, 83,
  79, 88, 55, 119, 86, 65, 56, 120, 116, 83, 104, 53, 106, 110, 73, 76, 89, 114, 85, 116,
  108, 118, 112, 120, 68, 111, 80, 84, 70, 106, 85, 47, 67, 109, 88, 84, 98, 80, 50, 43,
  100, 65, 114, 57, 76, 74, 48, 102, 51, 120, 51, 86, 73, 111, 97, 84, 98, 78, 81, 47,
  84, 104, 84, 79, 57, 57, 52, 122, 103, 89, 81, 85, 119, 72, 122, 103, 57, 108, 55, 82,
  89, 55, 90, 73, 87, 99, 80, 77, 50, 51, 48, 71, 104, 108, 53, 88, 85, 48, 54, 56,
  77, 78, 86, 71, 85, 65, 75, 78, 119, 73, 88, 119, 90, 73, 108, 99, 119, 106, 116, 50,
  56, 98, 73, 78, 113, 57, 51, 56, 110, 43, 87, 114, 57, 99, 76, 76, 51, 118, 48, 100,
  88, 107, 67, 48, 47, 90, 85, 98, 115, 107, 73, 75, 71, 103, 116, 83, 82, 89, 67, 111,
  106, 54, 78, 89, 112, 116, 73, 103, 68, 98, 67, 87, 87, 66, 43, 48, 79, 113, 81, 115,
  70, 66, 88, 100, 111, 98, 82, 81, 72, 122, 119, 118, 54, 106, 77, 76, 57, 67, 89, 100,
  53, 84, 74, 112, 83, 100, 82, 113, 47, 113, 54, 56, 57, 82, 88, 110, 81, 83, 114, 77,
  66, 74, 68, 105, 43, 84, 74, 99, 43, 120, 90, 105, 83, 111, 114, 52, 105, 80, 65, 75,
  113, 114, 53, 52, 108, 52, 99, 99, 66, 88, 102, 84, 67, 82, 88, 98, 81, 109, 78, 101,
  89, 98, 100, 68, 53, 81, 61, 61
};

static char data_chart[] = {
  111, 82, 87, 84, 77, 104, 85, 57, 52, 80, 111, 114, 116, 49, 52, 111, 86, 116, 54, 85,
  43, 52, 110, 117, 66, 102, 80, 56, 77, 111, 81, 74, 108, 119, 49, 80, 102, 110, 118, 89,
  88, 100, 122, 104, 66, 51, 79, 55, 117, 75, 116, 99, 75, 49, 109, 70, 57, 111, 75, 97,
  51, 110, 86, 57, 105, 101, 75, 55, 118, 70, 118, 110, 74, 90, 65, 112, 76, 55, 75, 82,
  98, 47, 105, 82, 111, 105, 87, 51, 48, 86, 52, 97, 97, 114, 80, 71, 73, 89, 110, 109,
  65, 48, 117, 69, 56, 112, 43, 83, 118, 47, 49, 50, 80, 43, 81, 115, 54, 66, 83, 115,
  84, 89, 74, 47, 66, 53, 104, 51, 76, 101, 83, 85, 105, 81, 98, 111, 53, 54, 78, 122,
  101, 82, 53, 69, 118, 66, 108, 99, 49, 114, 122, 65, 80, 117, 118, 56, 76, 88, 52, 101,
  104, 114, 84, 78, 57, 76, 115, 48, 88, 65, 55, 99, 43, 65, 85, 88, 78, 97, 85, 66,
  48, 54, 86, 56, 83, 57, 104, 111, 107, 76, 51, 43, 57, 70, 87, 51, 68, 83, 88, 122,
  90, 118, 73, 71, 43, 77, 68, 51, 97, 85, 98, 82, 56, 54, 52, 100, 120, 75, 80, 121,
  98, 68, 98, 50, 105, 82, 48, 86, 113, 47, 51, 119, 65, 88, 51, 68, 104, 114, 84, 87,
  84, 120, 98, 54, 82, 83, 121, 110, 70, 74, 83, 51, 48, 103, 52, 90, 52, 109, 81, 56,
  56, 100, 110, 104, 117, 74, 99, 120, 90, 51, 70, 79, 54, 111, 68, 65, 122, 54, 115, 103,
  74, 68, 69, 97, 115, 90, 122, 43, 81, 122, 53, 65, 111, 78, 74, 85, 116, 115, 99, 83,
  116, 76, 112, 119, 88, 114, 67, 99, 100, 82, 79, 100, 65, 51, 80, 51, 85, 73, 102, 56,
  50, 110, 53, 51, 82, 48, 54, 102, 118, 69, 101, 79, 57, 72, 118, 117, 103, 111, 78, 76,
  120, 50, 78, 48, 54, 71, 43, 108, 119, 111, 113, 98, 43, 67, 122, 69, 50, 54, 51, 53,
  88, 113, 86, 53, 71, 97, 84, 121, 103, 117, 90, 97, 65, 70, 84, 85, 115, 122, 47, 74,
  103, 56, 87, 109, 51, 52, 102, 52, 106, 121, 48, 43, 113, 51, 100, 101, 113, 78, 69, 99,
  65, 48, 77, 117, 107, 88, 87, 113, 67, 83, 90, 71, 84, 75, 102, 84, 84, 71, 102, 82,
  79, 53, 67, 84, 107, 73, 109, 103, 108, 85, 57, 121, 81, 51, 68, 109, 75, 84, 75, 82,
  65, 79, 107, 118, 57, 102, 116, 86, 106, 50, 75, 76, 82, 90, 119, 43, 99, 115, 85, 113,
  50, 113, 122, 57, 75, 105, 76, 79, 65, 98, 106, 103, 87, 79, 87, 76, 50, 117, 71, 71,
  107, 120, 116, 103, 121, 68, 87, 54, 54, 110, 100, 120, 112, 43, 115, 117, 90, 115, 87, 51,
  54, 76, 67, 67, 90, 117, 43, 69, 110, 97, 85, 100, 67, 86, 53, 55, 85, 65, 85, 86,
  111, 43, 119, 101, 43, 65, 79, 52, 88, 97, 106, 99, 120, 102, 98, 87, 89, 74, 118, 54,
  106, 52, 102, 85, 116, 48, 116, 67, 97, 82, 57, 98, 56, 110, 81, 47, 118, 54, 109, 70,
  115, 81, 48, 81, 97, 100, 111, 97, 68, 49, 74, 57, 87, 88, 77, 105, 97, 89, 69, 57,
  48, 121, 108, 71, 97, 47, 83, 109, 116, 73, 101, 110, 111, 86, 66, 102, 116, 111, 49, 85,
  52, 90, 81, 101, 78, 112, 75, 87, 51, 43, 50, 66, 71, 121, 84, 49, 114, 89, 74, 49,
  89, 47, 114, 84, 89, 52, 52, 105, 67, 107, 81, 70, 65, 65, 102, 75, 76, 55, 111, 67,
  118, 71, 113, 70, 122, 81, 103, 54, 83, 88, 118, 111, 53, 55, 110, 120, 121, 84, 53, 78,
  116, 65, 113, 104, 90, 109, 55, 86, 51, 90, 112, 65, 57, 122, 76, 122, 113, 52, 66, 110,
  108, 71, 84, 119, 112, 43, 99, 72, 47, 105, 113, 121, 103, 70, 66, 48, 68, 108, 57, 97,
  119, 55, 102, 71, 111, 68, 43, 75, 48, 119, 75, 109, 84, 116, 48, 113, 56, 99, 66, 52,
  114, 48, 83, 51, 114, 49, 100, 73, 51, 78, 50, 86, 106, 66, 54, 84, 56, 121, 49, 52,
  84, 120, 57, 103, 101, 109, 71, 78, 99, 85, 98, 116, 85, 98, 49, 79, 48, 117, 54, 122,
  122, 56, 66, 78, 116, 51, 72, 113, 103, 81, 101, 113, 81, 78, 67, 54, 80, 113, 51, 109,
  120, 101, 100, 84, 112, 81, 103, 101, 108, 66, 90, 79, 87, 67, 101, 115, 54, 88, 120, 104,
  103, 97, 111, 107, 74, 83, 108, 101, 67, 113, 116, 108, 108, 117, 111, 52, 55, 103, 57, 109,
  65, 98, 100, 103, 97, 69, 111, 121, 121, 106, 122, 67, 101, 98, 55, 119, 118, 105, 97, 52,
  109, 53, 119, 51, 90, 88, 78, 43, 110, 99, 104, 55, 70, 105, 115, 57, 115, 116, 113, 77,
  84, 99, 75, 47, 71, 115, 54, 55, 106, 119, 121, 108, 84, 78, 48, 68, 88, 57, 48, 119,
  74, 48, 70, 98, 84, 102, 83, 71, 116, 48, 104, 69, 109, 74, 97, 65, 72, 66, 55, 115,
  49, 118, 69, 115, 116, 80, 117, 49, 118, 67, 54, 112, 50, 121, 120, 69, 116, 65, 107, 117,
  73, 121, 122, 112, 70, 75, 73, 88, 51, 74, 85, 70, 119, 85, 81, 73, 66, 54, 49, 81,
  53, 54, 88, 116, 104, 55, 85, 120, 99, 108, 108, 100, 88, 110, 76, 81, 52, 100, 105, 115,
  80, 86, 79, 121, 52, 89, 87, 87, 97, 66, 89, 90, 120, 122, 65, 82, 119, 109, 71, 81,
  57, 68, 116, 117, 54, 108, 115, 84, 52, 102, 70, 119, 89, 84, 112, 67, 50, 119, 50, 50,
  67, 55, 106, 47, 101, 79, 113, 51, 118, 88, 82, 55, 114, 71, 117, 69, 109, 115, 57, 103,
  71, 121, 106, 101, 110, 88, 48, 106, 52, 66, 73, 71, 51, 68, 70, 43, 99, 72, 78, 48,
  113, 51, 86, 56, 81, 56, 70, 54, 110, 73, 80, 115, 112, 117, 55, 75, 67, 103, 106, 85,
  105, 87, 120, 81, 89, 80, 102, 50, 118, 113, 71, 84, 98, 122, 70, 49, 118, 66, 114, 115,
  47, 68, 118, 68, 112, 53, 102, 100, 52, 77, 54, 54, 118, 120, 52, 70, 57, 51, 51, 114,
  84, 86, 111, 98, 87, 101, 116, 117, 111, 86, 72, 113, 73, 70, 69, 102, 69, 83, 113, 49,
  86, 89, 51, 48, 74, 74, 120, 85, 90, 83, 116, 79, 57, 107, 73, 75, 121, 99, 107, 98,
  56, 56, 113, 70, 104, 104, 90, 81, 100, 51, 77, 90, 73, 52, 84, 99, 98, 75, 120, 53,
  56, 108, 107, 69, 109, 120, 75, 114, 56, 90, 90, 43, 54, 57, 88, 80, 75, 97, 107, 75,
  53, 107, 56, 76, 49, 57, 120, 53, 54, 79, 102, 54, 107, 115, 65, 117, 48, 110, 83, 54,
  56, 86, 80, 115, 57, 87, 75, 99, 88, 82, 65, 55, 102, 47, 105, 51, 55, 118, 73, 50,
  109, 105, 67, 105, 121, 116, 81, 112, 65, 117, 53, 54, 43, 114, 52, 112, 83, 73, 101, 52,
  101, 100, 89, 66, 66, 71, 81, 48, 75, 53, 89, 113, 118, 108, 79, 109, 84, 85, 113, 43,
  78, 117, 87, 114, 57, 47, 50, 105, 119, 51, 52, 73, 108, 114, 88, 88, 111, 71, 55, 75,
  108, 74, 119, 47, 116, 101, 83, 81, 47, 83, 69, 72, 89, 78, 90, 56, 56, 102, 118, 52,
  115, 110, 43, 115, 77, 83, 107, 77, 49, 70, 50, 112, 53, 67, 68, 112, 48, 84, 109, 74,
  47, 51, 115, 116, 89, 49, 102, 118, 50, 51, 89, 82, 70, 85, 57, 84, 66, 122, 74, 66,
  54, 81, 112, 83, 111, 77, 109, 51, 84, 89, 89, 74, 51, 69, 114, 52, 98, 53, 84, 78,
  100, 99, 49, 102, 68, 74, 80, 78, 113, 98, 52, 107, 99, 82, 67, 98, 78, 53, 43, 90,
  110, 77, 117, 97, 102, 69, 98, 100, 78, 51, 116, 115, 85, 83, 84, 106, 108, 57, 89, 66,
  100, 79, 108, 71, 73, 118, 79, 114, 53, 122, 117, 114, 48, 73, 85, 70, 109, 107, 48, 84,
  100, 56, 114, 102, 109, 81, 113, 108, 66, 74, 86, 107, 87, 66, 86, 102, 99, 51, 121, 82,
  113, 56, 82, 101, 101, 80, 55, 117, 87, 84, 49, 86, 67, 74, 110, 54, 102, 104, 109, 113,
  67, 103, 105, 55, 116, 43, 81, 90, 66, 88, 69, 52, 119, 65, 77, 54, 106, 118, 82, 49,
  109, 68, 83, 108, 115, 88, 101, 102, 47, 110, 74, 70, 100, 51, 72, 104, 57, 103, 104, 70,
  114, 47, 74, 69, 43, 50, 112, 113, 68, 56, 115, 97, 99, 84, 116, 79, 70, 117, 66, 121,
  121, 86, 116, 78, 121, 72, 57, 77, 56, 71, 73, 65, 116, 66, 105, 112, 55, 79, 70, 77,
  73, 82, 110, 49, 55, 67, 114, 109, 84, 109, 56, 119, 53, 74, 52, 100, 86, 108, 106, 73,
  122, 118, 114, 56, 69, 79, 86, 86, 75, 97, 110, 71, 101, 107, 117, 83, 72, 108, 77, 104,
  98, 110, 99, 88, 87, 43, 118, 54, 108, 122, 66, 43, 105, 49, 74, 71, 100, 66, 66, 49,
  52, 75, 119, 122, 90, 67, 52, 53, 115, 101, 69, 84, 102, 111, 121, 78, 81, 84, 79, 100,
  115, 117, 118, 99, 111, 86, 66, 81, 81, 80, 113, 82, 50, 108, 78, 77, 112, 43, 70, 119,
  99, 89, 112, 73, 112, 52, 115, 97, 43, 69, 108, 100, 83, 80, 47, 100, 78, 80, 84, 70,
  66, 50, 106, 55, 85, 89, 117, 53, 103, 80, 86, 112, 101, 72, 112, 89, 77, 104, 117, 98,
  83, 57, 55, 117, 114, 80, 106, 88, 109, 55, 105, 115, 105, 120, 56, 101, 111, 73, 71, 119,
  87, 73, 101, 56, 54, 85, 55, 113, 66, 87, 53, 71, 84, 101, 121, 98, 51, 80, 97, 114,
  69, 114, 87, 113, 103, 107, 104, 84, 72, 120, 57, 107, 87, 84, 77, 103, 73, 55, 122, 43,
  80, 81, 67, 104, 65, 51, 122, 75, 97, 97, 102, 53, 48, 47, 82, 79, 90, 101, 83, 79,
  70, 84, 104, 69, 50, 109, 105, 77, 43, 68, 48, 90, 80, 114, 56, 102, 83, 88, 82, 69,
  118, 70, 105, 122, 101, 110, 78, 86, 87, 52, 101, 56, 75, 121, 104, 71, 50, 81, 56, 53,
  121, 85, 103, 118, 81, 107, 99, 76, 108, 75, 70, 70, 49, 81, 119, 116, 85, 80, 104, 87,
  49, 47, 101, 107, 80, 84, 119, 90, 86, 116, 88, 56, 112, 84, 48, 51, 114, 101, 73, 87,
  115, 105, 117, 48, 90, 101, 79, 110, 51, 81, 65, 108, 102, 110, 119, 118, 53, 105, 75, 81,
  113, 107, 106, 120, 97, 49, 89, 116, 88, 51, 67, 117, 100, 74, 53, 47, 117, 108, 77, 52,
  87, 88, 76, 102, 52, 113, 47, 52, 122, 85, 49, 86, 66, 67, 90, 100, 97, 52, 84, 49,
  84, 120, 110, 116, 51, 78, 73, 102, 112, 121, 57, 108, 106, 120, 111, 76, 77, 54, 84, 121,
  85, 83, 78, 104, 66, 98, 113, 116, 118, 120, 66, 50, 106, 88, 104, 74, 109, 120, 69, 111,
  49, 107, 108, 79, 55, 98, 50, 121, 103, 104, 82, 107, 78, 83, 55, 56, 89, 97, 50, 53,
  102, 111, 106, 68, 98, 110, 107, 106, 120, 118, 107, 110, 122, 88, 79, 81, 66, 109, 113, 98,
  111, 99, 84, 88, 83, 87, 85, 109, 72, 83, 110, 115, 66, 48, 105, 112, 48, 52, 82, 99,
  54, 49, 70, 110, 111, 55, 69, 89, 117, 108, 103, 120, 52, 118, 49, 53, 121, 111, 81, 56,
  43, 73, 103, 78, 111, 68, 68, 110, 89, 107, 48, 99, 84, 54, 57, 104, 116, 76, 80, 102,
  68, 122, 76, 55, 74, 87, 87, 65, 56, 115, 47, 111, 122, 85, 120, 107, 102, 89, 98, 115,
  111, 99, 68, 70, 117, 102, 65, 101, 52, 122, 107, 75, 71, 104, 52, 84, 69, 101, 90, 117,
  66, 111, 83, 75, 109, 84, 97, 69, 82, 117, 71, 51, 66, 85, 67, 89, 68, 73, 117, 106,
  116, 105, 72, 75, 119, 82, 87, 71, 102, 55, 79, 118, 121, 121, 54, 112, 52, 112, 52, 82,
  121, 53, 74, 65, 73, 67, 114, 107, 55, 57, 48, 107, 98, 52, 114, 51, 97, 52, 78, 79,
  117, 50, 57, 107, 116, 120, 51, 103, 115, 104, 74, 69, 108, 57, 97, 77, 110, 49, 89, 86,
  55, 101, 83, 55, 82, 74, 89, 114, 55, 71, 72, 76, 115, 86, 49, 86, 80, 74, 103, 100,
  89, 105, 76, 99, 120, 114, 43, 67, 87, 70, 110, 98, 103, 99, 88, 79, 53, 107, 71, 88,
  82, 121, 79, 73, 97, 90, 89, 107, 83, 80, 53, 71, 80, 119, 115, 99, 78, 75, 65, 61
};

static char data_ext_charts[] = {
  83, 77, 49, 57, 76, 98, 75, 121, 83, 89, 111, 101, 89, 55, 72, 47, 74, 97, 114, 78,
  85, 88, 74, 43, 78, 102, 102, 102, 97, 111, 54, 116, 105, 110, 97, 89, 107, 88, 67, 112,
  106, 101, 53, 51, 69, 112, 82, 89, 84, 120, 68, 120, 70, 73, 113, 54, 100, 71, 89, 48,
  87, 68, 90, 50, 114, 88, 69, 54, 122, 65, 110, 107, 115, 121, 74, 107, 52, 77, 113, 75,
  100, 90, 52, 84, 57, 51, 106, 80, 107, 79, 103, 97, 112, 118, 87, 87, 113, 109, 78, 98,
  100, 67, 115, 52, 110, 70, 104, 52, 78, 87, 107, 66, 90, 87, 111, 73, 79, 79, 73, 77,
  77, 56, 100, 90, 56, 88, 83, 110, 113, 81, 104, 80, 121, 72, 54, 100, 69, 70, 86, 101,
  54, 113, 68, 56, 54, 112, 77, 71, 76, 48, 99, 122, 109, 49, 50, 87, 90, 120, 88, 97,
  114, 100, 109, 51, 105, 86, 114, 43, 102, 54, 117, 69, 113, 51, 109, 68, 71, 83, 51, 67,
  48, 70, 111, 83, 121, 74, 72, 52, 88, 55, 105, 74, 86, 65, 74, 49, 57, 51, 51, 99,
  115, 68, 54, 116, 119, 79, 78, 110, 119, 86, 49, 57, 48, 105, 122, 81, 79, 108, 66, 51,
  72, 77, 100, 105, 72, 85, 85, 75, 88, 84, 122, 76, 79, 113, 55, 99, 109, 102, 98, 43,
  54, 57, 86, 103, 115, 115, 68, 107, 48, 116, 112, 86, 69, 54, 72, 119, 74, 69, 82, 104,
  66, 98, 88, 52, 57, 108, 121, 113, 101, 109, 103, 70, 57, 72, 118, 74, 86, 57, 56, 49,
  73, 108, 68, 113, 118, 68, 90, 78, 57, 47, 101, 106, 78, 43, 107, 103, 103, 71, 104, 57,
  71, 119, 48, 56, 50, 66, 73, 112, 114, 56, 117, 116, 52, 65, 115, 101, 47, 108, 117, 70,
  116, 69, 113, 49, 52, 115, 53, 56, 69, 78, 117, 75, 111, 103, 109, 122, 115, 52, 103, 118,
  122, 54, 109, 73, 57, 53, 90, 73, 76, 101, 120, 54, 43, 69, 110, 77, 114, 90, 65, 121,
  116, 101, 111, 53, 80, 68, 122, 80, 109, 102, 120, 104, 105, 79, 56, 57, 57, 47, 67, 68,
  102, 53, 79, 77, 107, 53, 74, 56, 65, 85, 54, 103, 118, 87, 90, 54, 116, 103, 70, 67,
  88, 72, 53, 118, 119, 122, 70, 76, 115, 100, 120, 76, 103, 73, 113, 86, 121, 110, 117, 49,
  98, 113, 56, 108, 47, 107, 50, 121, 116, 47, 69, 118, 74, 97, 98, 87, 77, 119, 80, 76,
  83, 57, 102, 116, 113, 66, 86, 72
};

static char data_ext_imgs[] = {
  47, 117, 65, 85, 102, 87, 47, 97, 84, 118, 121, 78, 102, 112, 76, 109, 113, 65, 52, 75,
  70, 52, 86, 71, 65, 115, 102, 104, 115, 71, 99, 54, 78, 56, 65, 122, 111, 105, 69, 68,
  109, 108, 51, 79, 121, 112, 82, 107, 80, 70, 88, 99, 49, 52, 100, 89, 56, 70, 108, 76,
  82, 82, 51, 72, 47, 106, 116, 97, 120, 65, 78, 66, 113, 70, 101, 115, 112, 115, 103, 49,
  119, 87, 70, 103, 111, 102, 82, 78, 78, 121, 49, 116, 80, 105, 87, 109, 114, 75, 106, 118,
  90, 54, 49, 87, 108, 108, 74, 49, 119, 66, 76, 83, 83, 106, 52, 106, 87, 89, 117, 48,
  119, 79, 99, 89, 75, 79, 85, 107, 117, 114, 112, 48, 112, 98, 120, 86, 78, 54, 49, 85,
  103, 120, 117, 118, 110, 82, 122, 74, 70, 57, 120, 52, 106, 121, 54, 80, 115, 78, 74, 55,
  52, 112, 114, 55, 107, 74, 68, 115, 84, 71, 72, 51, 82, 67, 101, 57, 99, 56, 79, 97,
  82, 71, 111, 104, 110, 77, 105, 84, 112, 113, 51, 48, 103, 55, 113, 70, 117, 112, 109, 57,
  86, 110, 101, 111, 109, 81, 50, 55, 47, 55, 100, 112, 109, 118, 79, 80, 104, 67, 110, 121,
  105, 67, 99, 122, 110, 54, 121, 104, 112, 115, 79, 66, 98, 70, 71, 48, 90, 69, 118, 109,
  70, 115, 113, 113, 102, 52, 80, 116, 78, 71, 72, 51, 53, 100, 98, 108, 56, 54, 49, 84,
  50, 122, 70, 80, 104, 56, 86, 73, 51, 114, 71, 57, 53, 115, 47, 76, 106, 43, 120, 70,
  76, 69, 50, 73, 78, 48, 115, 88, 87, 84, 68, 111, 54, 50, 120, 87, 118, 90, 108, 82,
  87, 68, 66, 98, 77, 104, 53, 102, 102, 53, 76, 100, 43, 52, 82, 100, 56, 52, 103, 120,
  107, 43, 87, 117, 55, 72, 106, 73, 121, 89, 103, 75, 57, 74, 57, 80, 83, 48, 116, 116,
  71, 83, 119, 57, 49, 75, 66, 80, 107, 114, 119, 70, 55, 76, 103, 116, 106, 74, 86, 88,
  97, 106, 50, 71, 71, 47, 67, 101, 109, 73, 88, 85, 122, 100, 98, 66, 106, 106, 101, 53,
  77, 56, 67, 90, 66, 89, 70, 98, 113, 86, 89, 117, 116, 107, 120, 57, 67, 74, 53, 119,
  71, 120, 104, 84, 54, 67, 79, 99, 89, 87, 47, 113, 57, 105, 67, 97, 48, 54, 100, 76,
  115, 101, 50, 85, 97, 79, 56, 109, 70, 109, 50, 51, 81, 50, 71, 113, 71, 77, 50, 102,
  117, 103, 77, 67, 86, 49, 112, 102
};

static inline QString chartName(const QString &chart)
{
  QString str("<chart name=\"");
  int start = chart.find(str);
  if (start < 0)
    return QString::null;
  int pos = start + str.length();
  int end = chart.find("\"", pos);
  return chart.mid(pos, end - pos);
}

static inline QString imageName(const QString &image)
{
  QString str("<image name=\"");
  int start = image.find(str);
  if (start < 0)
    return QString::null;
  int pos = start + str.length();
  int end = image.find("\"", pos);
  return image.mid(pos, end - pos);
}

static inline QString imageLink(const QString &image)
{
  QString str(" link=\"");
  int start = image.find(str);
  if (start < 0)
    return QString::null;
  int pos = start + str.length();
  int end = image.find("\"", pos);
  return image.mid(pos, end - pos);
}

bool AQOdsGenerator::generateOds(const QString &fileNameOut) const
{
  qWarning("Funci�n no soportada");
  return false;
/*
  AQS *aqs = globalAQS;

  QByteArray baAux;

  QByteArray baMain;
  baAux.setRawData(data_main, sizeof(data_main));
  baMain = aqs->fromBase64(&baAux);
  baAux.resetRawData(data_main, sizeof(data_main));
  baMain = aqs->decryptInternal(&baMain);

  QByteArray baChart;
  baAux.setRawData(data_chart, sizeof(data_chart));
  baChart = aqs->fromBase64(&baAux);
  baAux.resetRawData(data_chart, sizeof(data_chart));
  baChart = aqs->decryptInternal(&baChart);

  QByteArray baExtCharts;
  baAux.setRawData(data_ext_charts, sizeof(data_ext_charts));
  baExtCharts = aqs->fromBase64(&baAux);
  baAux.resetRawData(data_ext_charts, sizeof(data_ext_charts));
  baExtCharts = aqs->decryptInternal(&baExtCharts);

  QByteArray baExtImgs;
  baAux.setRawData(data_ext_imgs, sizeof(data_ext_imgs));
  baExtImgs = aqs->fromBase64(&baAux);
  baAux.resetRawData(data_ext_imgs, sizeof(data_ext_imgs));
  baExtImgs = aqs->decryptInternal(&baExtImgs);

  QString strInput(str());
  QByteArray input(strInput.utf8());
  QByteArray content(aqs->xsltproc(&baMain, &input));

  QStringList charts;
  if (strInput.contains("<chart name=\"")) {
    charts = QStringList::split("__SEP__",
                                aqs->xsltproc(&baExtCharts, &input));
  }

  QValueList<QPair<QString, QByteArray> > objects;
  for (QStringList::const_iterator it = charts.begin(); it != charts.end(); ++it) {
    QCString chart(*it);
    if (chart.isEmpty() || chart == "\n")
      continue;
    objects.append(
      qMakePair(chartName(chart),
                aqs->xsltproc(&baChart, &chart))
    );
  }

  QStringList images;
  if (strInput.contains("<image name=\"")) {
    images = QStringList::split("__SEP__",
                                aqs->xsltproc(&baExtImgs, &input));
  }

  QValueList<QPair<QString, QString> > imgs;
  for (QStringList::const_iterator it = images.begin(); it != images.end(); ++it) {
    QCString image(*it);
    if (image.isEmpty() || image == "\n")
      continue;
    imgs.append(
      qMakePair(imageLink(image),
                imageName(image))
    );
  }

  AQZipWriter zip(fileNameOut);

  QByteArray mimeType(QCString("application/vnd.oasis.opendocument.spreadsheet"));
  mimeType.truncate(mimeType.size() - 1);
  zip.addFile("mimetype", mimeType);
  zip.addFile("content.xml", content);

  for (int i = 0; i < objects.size(); ++i) {
    QPair<QString, QByteArray> object = objects[i];
    QString path(object.first + "/content.xml");
    zip.addFile(path, object.second);
  }

  for (int i = 0; i < imgs.size(); ++i) {
    QPair<QString, QString> img = imgs[i];
    QString path("Pictures/" + img.second + ".png");
    QString link(img.first);
    QFile fil(link);
    if (!fil.open(IO_ReadOnly))
      continue;
    zip.addFile(path, fil.readAll());
  }

  QString manifest("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n"
                   "<manifest:manifest"
                   " xmlns:manifest=\"urn:oasis:names:tc:opendocument:xmlns:manifest:1.0\">\n"
                   " <manifest:file-entry"
                   " manifest:media-type=\"application/vnd.oasis.opendocument.spreadsheet\""
                   " manifest:version=\"1.2\""
                   " manifest:full-path=\"/\"/>\n"
                   " <manifest:file-entry"
                   " manifest:media-type=\"text/xml\""
                   " manifest:full-path=\"content.xml\"/>\n");

  for (int i = 0; i < objects.size(); ++i) {
    QPair<QString, QByteArray> object = objects[i];
    manifest += QString(" <manifest:file-entry"
                        " manifest:media-type=\"text/xml\""
                        " manifest:full-path=\"%1/content.xml\"/>\n")
                .arg(object.first);

    manifest += QString(" <manifest:file-entry"
                        " manifest:media-type=\"application/vnd.oasis.opendocument.chart\""
                        " manifest:full-path=\"%1/\"/>\n")
                .arg(object.first);
  }

  if (!imgs.isEmpty()) {
    for (int i = 0; i < imgs.size(); ++i) {
      QPair<QString, QString> img = imgs[i];
      manifest += QString(" <manifest:file-entry"
                          " manifest:media-type=\"image/png\""
                          " manifest:full-path=\"Pictures/%1.png\"/>\n")
                  .arg(img.second);
    }

    manifest += QString(" <manifest:file-entry"
                        " manifest:media-type=\"\""
                        " manifest:full-path=\"Pictures/\"/>\n");
  }

  manifest += "</manifest:manifest>";
  QByteArray mf(manifest.utf8());
  mf.truncate(mf.size() - 1);
  zip.addFile("META-INF/manifest.xml", mf);
  zip.close();

  return true; */
}
