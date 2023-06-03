#include <stdio.h>
#include <ctype.h>

typedef enum {
  LOOK,
  BAD,
  END,

  S0,
  S1,

  S00,
  S01,
  S10,

  S000,
  S001,
  S010,
  S011,
  S100
} state;

int main() {

  char c = getchar();
  int count = 0;
  state s = LOOK;
  while (c != EOF) {
    switch (s) {
      case LOOK:
        if (c == '0') s = S0;
        else if (c == '1') s = S1;
        else if (!isspace(c)) s = BAD;
        break;
      case BAD:
        if (isspace(c)) s = LOOK;
        break;
      case S0:
        if (c == '0') s = S00;
        else if (c == '1') s = S01;
        else s = isspace(c) ? LOOK : BAD;
        break;
      case S1:
        if (c == '0') s = S10;
        else s = isspace(c) ? LOOK : BAD;
        break;
      case S00:
        if (c == '0') s = S000;
        else if (c == '1') s= S001;
        else s = isspace(c) ? LOOK : BAD;
        break;
      case S01:
        if (c == '0') s = S010;
        else if (c == '1') s = S011;
        else s = isspace(c) ? LOOK : BAD;
        break;
      case S10:
        if (c == '0') s = S100;
        else s = isspace(c) ? LOOK : BAD;
        break;
      case S000:
      case S001:
      case S010:
      case S011:
      case S100:
        if (c == '0') s = END;
        else if (c == '1') s = END;
        else s = isspace(c) ? LOOK : BAD;
        break;
      case END:
        if (isspace(c)) {
          ++count;
          s = LOOK;
        } else s = BAD;
        break;
    }

    c = getchar();
  }

  printf("Count: %d\n", count);
  return 0;
}
