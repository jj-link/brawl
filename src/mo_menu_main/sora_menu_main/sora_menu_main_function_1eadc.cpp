#pragma force_active on
extern "C" {
extern void* g_GameGlobal;

unsigned int fn_2_1EADC() {
    unsigned char* g = (unsigned char*)g_GameGlobal;
    unsigned char* p = *(unsigned char**)(g + 0x24);
    unsigned int v = *(unsigned int*)(p + 0x7f4);
    return v / 60;
}
}
