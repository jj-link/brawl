#pragma force_active on
extern "C" {
extern int* g_GameGlobal;
}

extern "C" int fn_10_D07C() {
    int ret = 0x63;
    int v = ((unsigned char*)((int*)g_GameGlobal)[4])[4];
    if (v == 0x12) {
        ret = 0x3C;
    }
    return ret;
}
