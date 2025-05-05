#include <conio.h>
#include <stdio.h>
#include <time.h>
#include <windows.h>
int W = 10, H = 20, X, Y, Z, map[200] = {0};
int node[28] = {0x34567, 0x3569a, 0x24561, 0x24562, 0x24560, 0x2459a, 0x25689};
void init() {
    X = W / 2 - 2, Y = 0, Z = rand() % 7;
}
int fill(int v) {
    int c = 0;
    for (int k = node[Z]; k > 4; k >>= 4) {
        int x = X + (k & 3), y = Y + (k >> 2 & 3);
        c += 0 <= x && x < W && y < H ? map[y * W + x] ^= v : 1;
    }
    return c;
}
int set(int *k, int v) {
    *k += v;
    return fill(0) ? *k -= v, 1 : 0;
}
void clear() {
    for (int i = 0, c = 1; i < W * H;) {
        c *= map[i];
        if (++i % W == 0) {
            if (c) memmove(map + W, map, (i - W) * sizeof(int));
            c = 1;
        }
    }
}
int main() {
    srand(time(0));
    init();
    for (int i = 7; i < 28; ++i) {
        for (int k = node[i - 7], d = node[i] = k >> 16; k > 4; k >>= 4) {
            node[i] = node[i] << 4 | (k & 3) << 2 | d - (k >> 2 & 3);
        }
    }
    for (int c;;) {
        system("cls");
        fill(1);
        for (int i = 0; i < W * H; ++i % W || puts("#")) {
            printf(map[i] ? "[]" : "  ");
        }
        fill(1);
        c = getch();
        if (c == 'a') {
            set(&X, -1);
        } else if (c == 'd') {
            set(&X, 1);
        } else if (c == 's' && set(&Y, 1)) {
            if (Y == 0) {
                break;
            }
            fill(1);
            clear();
            init();
        } else if (c == 'w') {
            set(&Z, Z < 21 ? 7 : -21);
        }
    }
}
