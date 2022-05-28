/*
 * @copyright (c) 2008, Hedspi, Hanoi University of Technology
 * @author Huu-Duc Nguyen
 * @version 1.0
 */

#include <stdio.h>
#include "reader.h"

// File input
FILE *inputStream;
// Vị trí hiện tại
int lineNo, colNo;
// Kí tự hiện tại
int currentChar;

/**
 * @brief Nhập 1 kí tự từ input
 *
 * @return int mã ASCII của kí tự mới nhập
 */
int readChar(void)
{
  currentChar = getc(inputStream);
  colNo++;
  if (currentChar == '\n')
  {
    lineNo++;
    colNo = 0;
  }
  return currentChar;
}

/**
 * @brief Mở file
 *
 * @param fileName  đường dẫn đến file muốn mở
 * @return int  IO_SUCCESS nếu thành công, ngược lại trả về IO_ERROR
 */
int openInputStream(char *fileName)
{
  inputStream = fopen(fileName, "rt");
  if (inputStream == NULL)
    return IO_ERROR;
  lineNo = 1;
  colNo = 0;
  readChar();
  return IO_SUCCESS;
}

/**
 * @brief Đóng file input
 *
 */
void closeInputStream()
{
  fclose(inputStream);
}
