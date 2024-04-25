int W = 10, H = 20, S, x, y, z, i, k, n[112], m[200] = {}, h[256] = {};
int N[] = {0x34567, 0x3569a, 0x24561, 0x24562, 0x24560, 0x2459a, 0x25689};
void init() { x = W / 2 - 2, y = 0, z = rand() % 7 * 4; }
void mino(int d, int v) {
    int p = x + y * W + d % S, q = d == S ? (z + 84) % 112 : z, f = 1;
    for (i = 0; k = x + d % W + n[q + i] % W, i < 4;)
        f &= 0 <= k && k < W && (k = p + n[q + i]) < S && !(m[k] ^= v), ++i;
    if (f && (z = q, x += d % W, d - W || ++y) || d != W) return;
    for (y ? mino(0, 1) : exit(0), i = k = 0, init(); i < S; i % W || (k = 0))
        if ((k += m[i++]) == W) memmove(m + W, m, (i - W) * sizeof(int));
}
int main() {
    for (h['a']--, h['d']++, h['s'] = W, i = 0; i < 28; ++i)
        k = N[i / 4] >> (i % 4 * 4) & 15, n[i] = k % 4 + k / 4 * W;
    for (h['w'] = S = W * H, srand(time(0)), init(), i = 28; i < 112; ++i)
        k = n[i - 28], n[i] = k / W + ((N[i / 4 % 7] >> 16) - k % W) * W;
    for (; mino(0, 1), system("cls"), 1; mino(0, 1), mino(h[getch()], 0))
        for (i = 0; i < S; ++i % W || puts("#")) printf(m[i] ? "[]" : "  ");
}
