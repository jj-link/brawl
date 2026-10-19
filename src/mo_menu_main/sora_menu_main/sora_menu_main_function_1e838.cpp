#pragma force_active on
extern "C" {
extern void* g_GameGlobal;
void* fn_8004E5D8(void*, void*);
}

extern "C" unsigned short fn_2_1E838(void* arg) {
    unsigned short* result =
        static_cast<unsigned short*>(fn_8004E5D8(g_GameGlobal, arg));
    return result[0x32];
}
