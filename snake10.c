int main() {
    int W = 20, H = 12, S = W * H, l = 0, p = 0, d = 1, a, i;
    int m[S] = {}, h[256] = {['a'] = -1, ['d'] = 1, ['w'] = -W, ['s'] = W};
    for (m[1] = -1, srand(time(0));; Sleep(100)) {
        kbhit() && (i = h[getch()]) && (d = i), p = (S + p + d) % S;
        if ((a = m[p] != -1) || (m[rand() % S] = -1, l++), a && m[p]) break;
        for (m[p] = l, system("cls"), i = 0; i < S; ++i % W || _cputs("|\n"))
            _cputs(m[i] > 0 ? m[i] -= a, "()" : (m[i] ? "00" : "  "));
    }
}
