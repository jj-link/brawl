#pragma force_active on
extern int lbl_8042C0A0[];
extern void* g_GameGlobal;
extern "C" unsigned int* fn_8004E594(void*);

extern "C" int fn_8004F740(int arg0) {
    int i;
    int result = 1;
    for (i = 0; i < 12; i++) {
        if (arg0 == lbl_8042C0A0[i]) {
            unsigned int* bits = fn_8004E594(g_GameGlobal);
            result = (bits[i / 32] & (1 << (i % 32))) != 0;
            break;
        }
    }
    return result;
}
