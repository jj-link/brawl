#pragma force_active on
extern "C" {
extern void* g_GameGlobal;
unsigned int* fn_8004E640(void*);
unsigned int* fn_8004E64C(void*);
unsigned int* fn_8004E658(void*);
unsigned int* fn_8004E664(void*);
unsigned int* fn_8004E670(void*);
unsigned int* fn_8004E67C(void*);
unsigned int* fn_8004E688(void*);
unsigned int* fn_8004E694(void*);
}
extern "C" void fn_80053078(int a, int b, int c, int d, unsigned int* p) {
    p = 0;
    if ((unsigned char)(b + 0xF7) <= 1U) {
        if (d == 0) p = fn_8004E694(g_GameGlobal);
    } else if (c != 0) {
        p = fn_8004E664(g_GameGlobal);
    } else if (d != 0) {
        switch (a) {
        case 0:
        default: p = fn_8004E670(g_GameGlobal); break;
        case 1: p = fn_8004E67C(g_GameGlobal); break;
        case 2: p = fn_8004E688(g_GameGlobal); break;
        }
    } else {
        switch (a) {
        case 0:
        default: p = fn_8004E640(g_GameGlobal); break;
        case 1: p = fn_8004E64C(g_GameGlobal); break;
        case 2: p = fn_8004E658(g_GameGlobal); break;
        }
    }
    if (p != 0) {
        unsigned int v = *p;
        unsigned int n = 0x05F5E0FFU;
        if (v <= 0x05F5E0FEU) n = v + 1;
        *p = n;
    }
}