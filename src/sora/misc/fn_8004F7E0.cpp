#pragma force_active on
extern "C" {
unsigned int* fn_8004E594(void*);
}
extern void* g_GameGlobal;
extern int lbl_8042C0A0[];

extern "C" void fn_8004F7E0(int arg0) {
    for (int i = 0; i < 12; i++) {
        if (arg0 == lbl_8042C0A0[i]) {
            unsigned int* bits = fn_8004E594(g_GameGlobal);
            bits[i / 32] |= 1u << (i % 32);
        }
    }
}
