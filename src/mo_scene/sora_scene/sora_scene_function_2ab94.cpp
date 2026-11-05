#pragma force_active on
extern "C" {
extern int* fn_8004E5F8(void*);
extern int* fn_8004E580(void*);
extern void* g_GameGlobal;

int fn_1_2AB94(int arg0) {
    int result = 0;

    int* p = fn_8004E5F8(g_GameGlobal);
    if (!(p[5] & 1)) {
        int* p2 = fn_8004E5F8(g_GameGlobal);
        p2[5] |= 1;
    }

    p = fn_8004E5F8(g_GameGlobal);
    if ((p[5] & 0x04000000) == 0 && arg0 >= 4) {
        int* p2 = fn_8004E5F8(g_GameGlobal);
        p2[5] |= 0x04000000;
    }

    p = fn_8004E580(g_GameGlobal);
    if ((p[1] & 0x100) == 0) {
        char* gg = (char*)g_GameGlobal;
        char* obj1 = *(char**)(gg + 0x30);
        char* obj2 = *(char**)(gg + 0x8);

        if (((*(unsigned char*)(obj1 + 0x606) >> 7) & 1) &&
            (*(unsigned char*)(obj2 + 0xf4) == 7 ||
             *(unsigned char*)(obj2 + 0xf4) == 0x15)) {
            result = 1;
        }

        if (*(unsigned char*)(obj2 + 0x98) == 7 ||
            *(unsigned char*)(obj2 + 0x98) == 0x15) {
            result = 1;
        }

        if (result) {
            int* p2 = fn_8004E580(gg);
            p2[1] |= 0x80;
        }
    }

    return result;
}
}