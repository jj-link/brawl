#pragma force_active on
extern "C" {
extern void* g_GameGlobal;
void* fn_8004E5D8(void*, void*);

unsigned int fn_2_1E8C8(void* arg) {
    return static_cast<unsigned int*>(fn_8004E5D8(g_GameGlobal, arg))[22];
}
}
