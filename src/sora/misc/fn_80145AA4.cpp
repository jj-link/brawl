#pragma force_active on

extern "C" unsigned char lbl_8059E742;
extern "C" unsigned int g_NtAIDBitmap;
extern "C" int* lbl_805A03A8;

extern "C" int fn_80145AA4(void) {
    int* p = lbl_805A03A8;
    unsigned char aid = lbl_8059E742;
    unsigned int bitmap = g_NtAIDBitmap;
    unsigned int i;
    for (i = 0; i < 4; i++) {
        unsigned char a = i;
        if (i != aid && (bitmap & (1 << a)) && p[0x16 + i * 0x394] != p[0x17 + i * 0x394]) {
            break;
        }
    }
    return (i == 4);
}