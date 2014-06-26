#include <cstdio>

int main() {
  int N;
  char *orig_line, *new_line;
  scanf("%d\n", &N);

  orig_line = new char[N];
  new_line = new char[N];

  for (int i = 0; i < N; i++) {
    scanf("%c\n", &orig_line[i]);
  }

  int front = 0, back = N - 1;
  int line_count = 0;;

  while (front <= back) {
    bool left = false;
    for (int i = 0; front + i <= back; i++) {
      if (orig_line[front + i] < orig_line[back - i]) {
	left = true;
	break;
      } else if (orig_line[front + i] > orig_line[back - i]) {
	left = false;
	break;
      }
    }

    if (left) putchar(orig_line[front++]);
    else putchar(orig_line[back--]);
    if (++line_count == 80) {
      line_count = 0;
      putchar('\n');
    }
  }
}
