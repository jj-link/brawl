#pragma force_active on
extern "C" {
extern unsigned char* g_GameGlobal;

unsigned int fn_2_1EB00() {
    unsigned char* gg = (unsigned char*)g_GameGlobal;
    unsigned char* sub = *(unsigned char**)(gg + 0x24);
    unsigned int v = *(unsigned int*)(sub + 0x7f8);
    return (v / 15u) >> 2;
}
}
