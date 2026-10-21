#pragma force_active on
extern unsigned char* g_GameGlobal;

extern "C" {
unsigned int fn_8014FDF0() {
    unsigned char* p = *(unsigned char**)((unsigned char*)g_GameGlobal + 0x34);
    return (p[0x83] >> 1) & 1;
}
}
