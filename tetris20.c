int W = 10, H = 20, S, x, y, z, t, i = 28, k, n[112], m[200] = {}, h[256] = {};
int N[] = {0x34567, 0x3569a, 0x24561, 0x24562, 0x24560, 0x2459a, 0x25689};
void init() { x = W / 2 - 2, y = 0, t = 0, z = rand() % 7 * 4; }
void mino(int d, int v) {
    int p = x + y * W + d % S, R = d == S ? (z + 84) % 112 : z, f = 1;
    for (i = 0; k = x + d % W + n[R + i] % W, i < 4;)
        f &= 0 <= k && k < W && (k = p + n[R + i]) < S && !(m[k] ^= v), ++i;
    if (f && (z = R, x += d % W, d - W || ++y) || d != W) return;
    for (y ? mino(0, 1) : exit(0), i = k = 0, init(); i < S; i % W || (k = 0))
        if ((k += m[i++]) == W) memmove(m + W, m, (i - W) * sizeof(int));
}
int main() {
    for (; i--;) k = N[i / 4] >> (i % 4 * 4) & 15, n[i] = k % 4 + k / 4 * W;
    for (h['a']--, h['d']++, h['w'] = S = W * H, h['s'] = W, i = 27; i < 111;)
        k = n[++i - 28], n[i] = k / W + ((N[i / 4 % 7] >> 16) - k % W) * W;
    for (srand(time(0)), init();; Sleep(100), system("cls"), mino(0, 1)) {
        mino(kbhit() ? h[getch()] : t > 10 ? t = 0, W : 0, 0), mino(0, 1);
        for (i = 0; i < S; ++i % W || puts("#")) printf(m[i] ? "[]" : "  ");
    }
}
