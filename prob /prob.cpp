#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  FILE *InputFile;
  FILE *OutputFile;
  InputFile = fopen("input.txt", "r");
  OutputFile = fopen("output.txt", "w");
  int w, h, d, w1, h1, d1;
  (void)fscanf(InputFile, "%d %d %d %d %d %d", &w, &h, &d, &w1, &h1, &d1);
  if (h1 == h && d1 == d) {
    w -= w1;
    h1 = 0;
    d1 = 0;
    w1 = 0;
  } else if (h1 == h && w1 == w) {
    d -= d1;
    h1 = 0;
    d1 = 0;
    w1 = 0;
  } else if (w1 == w && d1 == d) {
    h -= h1;
    h1 = 0;
    d1 = 0;
    w1 = 0;
  }
  int cols = 2 * d + 4 * w + 1;
  int rows = 3 * h + 1 + 2 * d;
  char **array = (char **)malloc(rows * sizeof(char *));
  for (int i = 0; i < rows; i++) {
    array[i] = (char *)malloc(cols * sizeof(char));
  }
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      array[i][j] = 'A';
    }
  }
  int row = 0;
  int col = 0;
  for (int i = 0; i < 2 * d + 1; ++i) {
    for (int j = 0; j < 2 * d - i; ++j) {
      array[row][col] = '.';
      ++col;
    }
    if (i % 2 == 0) {
      for (int j = 0; j < 4 * w + 1; ++j) {
        if (j % 4 == 0) {
          array[row][col] = '+';
          ++col;
        } else {
          array[row][col] = '-';
          ++col;
        }
      }
    } else {
      for (int j = 0; j < 4 * w + 1; ++j) {
        if (j % 4 == 0) {
          array[row][col] = '/';
          ++col;
        } else {
          array[row][col] = ' ';
          ++col;
        }
      }
    }
    for (int j = 2 * d - i; j < 2 * d; ++j) {
      if ((i + d) % 3 == 0) {
        if (j % 6 == 0) {
          array[row][col] = ' ';
          ++col;
        } else if (j % 6 == 1) {
          array[row][col] = '|';
          ++col;
        } else if (j % 6 == 2) {
          array[row][col] = '/';
          ++col;
        } else if (j % 6 == 3) {
          array[row][col] = '|';
          ++col;
        } else if (j % 6 == 4) {
          array[row][col] = ' ';
          ++col;
        } else if (j % 6 == 5) {
          array[row][col] = '+';
          ++col;
        }
      } else if ((i + d) % 3 == 1) {
        if (j % 6 == 0) {
          array[row][col] = ' ';
          ++col;
        } else if (j % 6 == 1) {
          array[row][col] = '+';
          ++col;
        } else if (j % 6 == 2) {
          array[row][col] = ' ';
          ++col;
        } else if (j % 6 == 3) {
          array[row][col] = '|';
          ++col;
        } else if (j % 6 == 4) {
          array[row][col] = '/';
          ++col;
        } else if (j % 6 == 5) {
          array[row][col] = '|';
          ++col;
        }
      } else {
        if (j % 6 == 0) {
          array[row][col] = '/';
          ++col;
        } else if (j % 6 == 1) {
          array[row][col] = '|';
          ++col;
        } else if (j % 6 == 2) {
          array[row][col] = ' ';
          ++col;
        } else if (j % 6 == 3) {
          array[row][col] = '+';
          ++col;
        } else if (j % 6 == 4) {
          array[row][col] = ' ';
          ++col;
        } else if (j % 6 == 5) {
          array[row][col] = '|';
          ++col;
        }
      }
    }

    ++row;
    col = 0;
  }
  for (int i = 1; i < 3 * h + 1; ++i) {
    for (int j = 0; j < 4 * w + 1; ++j) {
      if (i % 3 == 0) {
        if (j % 4 == 0) {
          array[row][col] = '+';
          ++col;
        } else {
          array[row][col] = '-';
          ++col;
        }
      } else {
        if (j % 4 == 0) {
          array[row][col] = '|';
          ++col;
        } else {
          array[row][col] = ' ';
          ++col;
        }
      }
    }
    for (int j = 0; j < 2 * d; ++j) {
      if (i + j > 3 * h - 1) {
        break;
      }
      if (i % 3 == 0) {
        if (j % 6 == 0) {
          array[row][col] = ' ';
          ++col;
        } else if (j % 6 == 1) {
          array[row][col] = '|';
          ++col;
        } else if (j % 6 == 2) {
          array[row][col] = '/';
          ++col;
        } else if (j % 6 == 3) {
          array[row][col] = '|';
          ++col;
        } else if (j % 6 == 4) {
          array[row][col] = ' ';
          ++col;
        } else if (j % 6 == 5) {
          array[row][col] = '+';
          ++col;
        }
      } else if (i % 3 == 1) {
        if (j % 6 == 0) {
          array[row][col] = ' ';
          ++col;
        } else if (j % 6 == 1) {
          array[row][col] = '+';
          ++col;
        } else if (j % 6 == 2) {
          array[row][col] = ' ';
          ++col;
        } else if (j % 6 == 3) {
          array[row][col] = '|';
          ++col;
        } else if (j % 6 == 4) {
          array[row][col] = '/';
          ++col;
        } else if (j % 6 == 5) {
          array[row][col] = '|';
          ++col;
        }
      } else {
        if (j % 6 == 0) {
          array[row][col] = '/';
          ++col;
        } else if (j % 6 == 1) {
          array[row][col] = '|';
          ++col;
        } else if (j % 6 == 2) {
          array[row][col] = ' ';
          ++col;
        } else if (j % 6 == 3) {
          array[row][col] = '+';
          ++col;
        } else if (j % 6 == 4) {
          array[row][col] = ' ';
          ++col;
        } else if (j % 6 == 5) {
          array[row][col] = '|';
          ++col;
        }
      }
    }
    ++row;
    col = 0;
  }
  int d_left = d - d1;
  int w_left = w - w1;
  int dx = 2 * d1 + 4 * w_left;
  int dy = 2 * d_left;
  for (int i = 0; i <= 2 * d1; ++i) {
    for (int j = 0; j <= 4 * w1; ++j) {
      for (int k = 0; k <= 3 * h1; ++k) {
        array[dy + i + k][dx + j - i] = 'A';
      }
    }
  }
  for (int i = 0; i <= 2 * d1; ++i) {
    for (int j = 0; j <= 4 * w1; ++j) {
      for (int k = 0; k <= 3 * h1; ++k) {
        // if (dy + i + k < 0 || dx + j - i < 0) {
        //   continue;
        // }
        if (array[dy + i + k][dx + j - i] != 'A') {
          continue;
        }
        if (i % 2 == 1 && j == 0 && k % 3 == 0) {
          array[dy + i + k][dx + j - i] = '/';
        } else if (i % 2 == 0 && j == 0 && k % 3 != 0) {
          array[dy + i + k][dx + j - i] = '|';
        } else if (i % 2 == 0 && j == 0 && k % 3 == 0) {
          array[dy + i + k][dx + j - i] = '+';
        } else if (i % 2 == 0 && k == 3 * h1 && j % 4 != 0) {
          array[dy + i + k][dx + j - i] = '-';
        } else if (i == 0 && k % 3 == 0 && j % 4 != 0) {
          array[dy + i + k][dx + j - i] = '-';
        } else if (i == 0 && (k % 3 == 0) && (j % 4 == 0)) {
          array[dy + i + k][dx + j - i] = '+';
        } else if (i == 0 && k % 3 != 0 && j % 4 == 0) {
          array[dy + i + k][dx + j - i] = '|';
        } else {
          array[dy + i + k][dx + j - i] = ' ';
        }
      }
    }
  }
  for (int i = 0; i <= 2 * d1; ++i) {
    for (int j = 0; j <= 4 * w1; ++j) {
      //  if (dy + i + 3 * h1 < 0 || dx + j - i < 0) {
      //     continue;
      //   }
      if (i % 2 == 0) {
        if (j % 4 == 0) {
          array[dy + i + 3 * h1][dx + j - i] = '+';

        } else {
          array[dy + i + 3 * h1][dx + j - i] = '-';
        }
      } else {
        if (j % 4 == 0) {
          array[dy + i + 3 * h1][dx + j - i] = '/';
        } else {
          array[dy + i + 3 * h1][dx + j - i] = ' ';
        }
      }
    }
  }
  for (int i = rows - 1; i >= 0; --i) {
    for (int j = 4 * w + 1 + rows - 1 - i; j < cols; ++j) {
      array[i][j] = ' ';
    }
  }
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      if (array[i][j] != 'A') {
        fprintf(OutputFile, "%c", array[i][j]);
      } else {
        fprintf(OutputFile, " ");
      }
    }
    if (i != rows - 1) {
      fprintf(OutputFile, "\n");
    }
  }
  for (int i = 0; i < rows; i++) {
    free(array[i]);
  }
  free(array);
  fclose(InputFile);
  fclose(OutputFile);
  return 0;
}
