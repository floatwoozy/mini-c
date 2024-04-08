#include <conio.h>
#include <stdio.h>
#include <time.h>
#include <windows.h>

#define MAX_SIZE 0x1000
int width, height, speed, wall, size, l, r, len, head, apple, delta;
int map[MAX_SIZE], queue[MAX_SIZE], input_map[255] = {['a'] = -1, ['d'] = 1};
short COLOR_AIR = 240, COLOR_SNAKE = 192, COLOR_FOOD = 160, COLOR_TEXT = 15;
HANDLE hOut;
COORD coord;
void set_brush(int x, int y, short color) {
    coord.X = x, coord.Y = y;
    SetConsoleCursorPosition(hOut, coord);
    SetConsoleTextAttribute(hOut, color);
}
void set_value(int index, short color, int value) {
    set_brush(index % width * 2, index / width, color), printf("  ");
    if (value >= 0) map[index] = value;
}
void new_food() {
    while (map[apple = rand() % size] || apple == head) {}
    set_value(apple, COLOR_FOOD, -1);
}
int get_wall(FILE **f) {
    int c = *f ? fgetc(*f) : '\n';
    return c == '\n' ? -1 : c == EOF ? fclose(*f), *f = NULL, -1 : c == '1';
}
void build() {
    FILE *f_wall = wall ? wall = 0, fopen("WALL.txt", "a+") : NULL;
    size = width * height, input_map['w'] = -width, input_map['s'] = width;
    l = r = head = 0, len = delta = 1, set_brush(0, 0, COLOR_TEXT);
    system("cls"), set_brush(0, 0, COLOR_AIR);
    for (int y = 0, i = 0, x, c; y < height; ++y, printf("\n"))
        for (x = c = 0; ~c && ~(c = get_wall(&f_wall)) || x < width; ++x)
            if (x < width) printf((map[i++] = c == 1) ? wall++, "[]" : "  ");
    for (f_wall &&fclose(f_wall); head < size && map[head] != 0;) head++;
}
void default_config() { width = height = speed = 10, wall = 0; }
void init() {
    if (build(), head >= size || wall >= size - 1) {
        set_brush(0, height, COLOR_TEXT), puts("Init Failed!\nFallback...");
        getch(), default_config(), build();
    }
    set_value(queue[++r] = head, COLOR_SNAKE, 1), new_food();
}
void game() {
    for (int st = clock(), et = 0, c; et += 1000 / speed;) {
        if (kbhit() && (c = getch())) {
            if (c == 27) break;
            if (c == ' ') st -= clock(), getch(), st += clock();
            if ((c = input_map[c]) != 0 && delta != -c) delta = c;
        }
        set_value(head, COLOR_SNAKE, -1);
        int y = (head / width + delta / width + height) % height;
        head = y * width + (head + delta + width) % width;
        if (head == apple) ++len >= size - wall ? map[head] = 1 : new_food();
        else { set_value(queue[l = (l + 1) % size], COLOR_AIR, 0); }
        if (map[head]) break;
        set_value(queue[r = (r + 1) % size] = head, COLOR_SNAKE ^ 0x80, 1);
        set_brush(0, height, COLOR_TEXT);
        printf("Score:%d\nhead:(%d,%d) ", len, head % width, y);
        printf("food:(%d,%d)    ", apple % width, apple / width);
        for (int i; (i = clock() - st) < et; Sleep(5)) {
            set_brush(12, height, COLOR_TEXT);
            printf("Time:%d.%02ds", i / 1000, i % 1000 / 10);
        }
    }
}
void menu(int color) {
    set_brush(0, height, color);
    printf("Size:%dx%d /Wall:%d /", width, height, wall);
    printf("Speed:%d(step/s)        \n\n", speed);
    puts("<Menu>    [Space] Start Game [1] Map Resize  [3] -Speed");
    puts("[5]Refresh  [Esc] Exit Game  [2] Enable Wall [4] +Speed");
    puts("<Game>  [A/S/D/W] Move     [Esc] Stop    [Space] Pause");
}
int read(int min, int max) {
    int x = 0, c;
    while ('0' <= (c = getchar()) && c <= '9') x = x * 10 + (c - '0');
    return x < min ? min : (x > max ? max : x);
}
int main() {
    hOut = GetStdHandle(STD_OUTPUT_HANDLE), SetConsoleOutputCP(65001);
    srand((unsigned) time(0)), default_config(), init();
    for (int c; c != 27; fflush(stdin), c == '5' ? init() : 0) {
        if (menu(COLOR_TEXT), (c = getch()) == ' ') {
            menu(COLOR_TEXT & 0xf0), game(), c = '5';
            set_brush(0, height + 2, COLOR_TEXT);
            puts(len < size - wall ? "Game over!" : "(´･ω･`)?");
            for (puts("Press [Space] to continue."); getch() != ' ';) {}
        } else if (c == '1') {
            printf("Enter width and height (1x1 ~ 80x48):");
            c = '5', width = read(1, 80), height = read(1, 48);
        }
        if (c == '2') wall = !wall, c = '5';
        if (c == '3' && 1 < speed) speed -= speed > 10 ? 5 : 1;
        if (c == '4' && speed < 100) speed += speed >= 10 ? 5 : 1;
    }
}
