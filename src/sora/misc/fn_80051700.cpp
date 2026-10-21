#pragma force_active on
extern "C" {
extern int fn_8005630C(int);
extern int g_GameGlobal;

int fn_80051700(void) {
    int p = *(int*)(g_GameGlobal + 8);
    return fn_8005630C(*(unsigned char*)(p + 0x60) | 1);
}
}
