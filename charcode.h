/*
 * @copyright (c) 2008, Hedspi, Hanoi University of Technology
 * @author Huu-Duc Nguyen
 * @version 1.0
 */

#ifndef __CHARCODE_H__
#define __CHARCODE_H__

typedef enum
{
  // Kí tự khoảng trắng
  CHAR_SPACE,
  // Kí tự [a-zA-z]
  CHAR_LETTER,
  // Kí tự [0-9]
  CHAR_DIGIT,
  // Kí tự '+'
  CHAR_PLUS,
  // Kí tự '-'
  CHAR_MINUS,
  // Kí tự '*'
  CHAR_TIMES,
  // Kí tự '/'
  CHAR_SLASH,
  // Kí tự '<'
  CHAR_LT,
  // Kí tự '>'
  CHAR_GT,
  // Kí tự '!'
  CHAR_EXCLAIMATION,
  // Kí tự '='
  CHAR_EQ,
  // Kí tự ','
  CHAR_COMMA,
  // Kí tự '.'
  CHAR_PERIOD,
  // Kí tự ':'
  CHAR_COLON,
  // Kí tự ':'
  CHAR_SEMICOLON,
  // Kí tự '\''
  CHAR_SINGLEQUOTE,
  // Kí tự '('
  CHAR_LPAR,
  // Kí tự ')'
  CHAR_RPAR,
  // Kí tự ngoài bảng chữ cái
  CHAR_UNKNOWN
} CharCode;

#endif
