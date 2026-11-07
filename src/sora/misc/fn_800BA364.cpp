#pragma force_active on
extern unsigned int lbl_80407BF8[4];

struct E { int a; unsigned char b, c, x, y; };
struct S { unsigned char pad[0x2C]; E e[4]; };

extern "C" void fn_800BA364(S *s, unsigned int m) {
    for (int i = 0; i < 4; i++) {
        if (m & lbl_80407BF8[i]) {
            s->e[i].a = 1;
            s->e[i].b = 0;
            s->e[i].c = 0;
        }
    }
}
