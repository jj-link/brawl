#pragma force_active on
extern int fn_80396EEC(int, int, int);

void fn_803974A4(int a, void *b) {
    void (*func)(void *, int, int);

    if (fn_80396EEC(a, (int)b, 0) != 0) {
        func = *(void (**)(void *, int, int))((char *)b + 0x1C);
        if (func != 0) {
            func(b, 4, 0);
        }
    }
}
