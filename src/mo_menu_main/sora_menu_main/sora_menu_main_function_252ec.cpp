#pragma force_active on
extern "C" void* g_GameGlobal;
extern "C" void* fn_8004E5D8(void*, void*);

extern "C" unsigned short fn_2_252EC(void* arg) {
    unsigned short* p = static_cast<unsigned short*>(fn_8004E5D8(g_GameGlobal, arg));
    return p[0x48 / 2];
}
