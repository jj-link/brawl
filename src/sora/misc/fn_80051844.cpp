#pragma force_active on
extern "C" {
extern int g_GameGlobal;
int fn_80051718(int a, int b);

int fn_80051844(int arg) {
    unsigned char v = *(unsigned char*)(*(int*)((char*)g_GameGlobal + 8) + 0x61);
    return fn_80051718(v, arg);
}
}
