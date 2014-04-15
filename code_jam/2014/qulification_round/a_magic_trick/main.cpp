#include <cstdio>
#include <algorithm>
#include <cassert>

using namespace std;

int main()
{
  int count;
  scanf("%d", &count);

  for (int i = 1; i <= count; i++) {
    int before_row, after_row;
    int cards[4][4];
    int candidates[4];
    scanf("%d", &before_row);
    //    printf("%d\n", before_row);
    for (int r = 0; r < 4; r++) {
      scanf("%d %d %d %d", &cards[r][0], &cards[r][1], &cards[r][2], &cards[r][3]);
      //      printf("%d %d %d %d\n", cards[r][0], cards[r][1], cards[r][2], cards[r][3]);
    }

    for (int c = 0; c < 4; c++) {
      candidates[c] = cards[before_row-1][c];
    }

    scanf("%d", &after_row);
    //    printf("%d\n", after_row);
    for (int r = 0; r < 4; r++) {
      scanf("%d %d %d %d", &cards[r][0], &cards[r][1], &cards[r][2], &cards[r][3]);
      //      printf("%d %d %d %d\n", cards[r][0], cards[r][1], cards[r][2], cards[r][3]);
    }

    int match = 0;
    int num = -1;
    for (int c = 0; c < 4; c++) {
      for (int j = 0; j < 4; j++) {
        if (candidates[c] == cards[after_row-1][j]) {
          match++;
          num = candidates[c];
        }
      }
    }
    switch (match) {
    case 0:
      printf("Case #%d: Volunteer cheated!\n", i);
      break;
    case 1:
      printf("Case #%d: %d\n", i, num);
      break;
    default:
      printf("Case #%d: Bad magician!\n", i);
      break;
    }
  }
}
