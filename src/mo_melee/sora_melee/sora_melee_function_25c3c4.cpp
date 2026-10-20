#pragma force_active on
extern "C" void fn_27_25C3C4(void* self) {
    unsigned char* p = (unsigned char*)self;
    if (p[0x51] == 0) {
        extern void setSlowRate__10GameGlobalFUc(void*, unsigned char);
        extern void* g_GameGlobal;
        setSlowRate__10GameGlobalFUc(g_GameGlobal, 1);
        *(unsigned int*)(p + 0x48) = 8;
    } else {
        *(unsigned int*)(p + 0x48) = 11;
    }
}
