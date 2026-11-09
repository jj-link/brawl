#pragma force_active on
extern void* g_GameGlobal;
extern const float lbl_805A2468, lbl_805A2484, lbl_805A2488, lbl_805A248C, lbl_805A24A4;
extern "C" float fn_800E8E60(void* arg0, unsigned arg1, int arg2) {
    char* sub = *(char**)((char*)g_GameGlobal + 0x18);
    int kind = *(int*)((char*)arg0 + (arg1 << 2) + 0xA8);
    float r;
    if (kind == 3) return lbl_805A2484;
    if (*(unsigned char*)(sub + 2) == 0) {
        if (kind == 0) r = lbl_805A2468 + (float)arg1;
        else r = lbl_805A2488;
    } else {
        unsigned char v = *(unsigned char*)(sub + arg1 * 0x2AC + 0x2A);
        if (v == 2) r = lbl_805A24A4;
        else r = lbl_805A2468 + (float)v;
    }
    if (arg2 != 0) r += lbl_805A248C;
    return r;
}