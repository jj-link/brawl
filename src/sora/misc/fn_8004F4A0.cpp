#pragma force_active on

extern "C" {
extern void* g_GameGlobal;
extern const unsigned char lbl_80406968[];
unsigned int* fn_8004E580(void* gg);
unsigned char exchangeGmCharacterKindToMuCharKind__6muMenuFiii(int c);
}

extern "C" int fn_8004F4A0(int arg0) {
    unsigned int* flags = fn_8004E580(g_GameGlobal);
    unsigned char kind = (unsigned char)exchangeGmCharacterKindToMuCharKind__6muMenuFiii((unsigned char)arg0);
    int idx;
    const unsigned char* p = lbl_80406968;
    int i;

    for (i = 0, idx = 0; i < 14; i++) {
        if ((int)kind == (int)p[2]) {
            kind = (lbl_80406968 + idx * 4)[0];
            goto found;
        }
        p += 4;
        idx++;
    }
    kind = 0xE;
found:
    if (kind == 0xE || ((1u << (kind * 3 + 1) % 32) & flags[(kind * 3 + 1) / 32])) {
        return 1;
    }
    return 0;
}
