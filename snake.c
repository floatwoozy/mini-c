#include <windows.h>
#include <conio.h>
#include <time.h>
int main() {
    int W = 20, H = 12, S = W * H, m[S], l = 3, p = W + 1, d = 1, x, i = -1;
    while (++i < S) m[i] = !(i / W % (H - 1) && i % W % (W - 1)) * -2;
    for (srand(time(0)), m[p + d] = -1;; Sleep(100)) {
        if (kbhit() && ~(i = getch(), x = i - 'w' ? i - 's' ? 0 : W : -W))
            x = i - 'a' ? i - 'd' ? x : 1 : -1, x && d + x && (d = x);
        if (x = 1, m[p += d] == -1 || m[p] && (exit(0), 1))
            while (m[i = rand() % S] || (m[i] = -1, l++, x = 0)) {}
        for (m[p] = l, system("cls"), i = 0; i < S; ++i % W || _cputs("\n"))
            _cputs(m[i] > 0 ? m[i] -= x, "()" : "  \0<>\0[]" - m[i] * 3);
    }
}
