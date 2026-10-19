#pragma force_active on
extern "C" void fn_8004EFA8(void* a, void* b);
extern void* g_GameGlobal;

extern "C" {
void fn_40_47D80(char* self) {
    int idx = *(int*)(self + 0x1414);
    char* p = self + idx * 0x58;
    short s = *(short*)(p + 0x202);
    void* arg = *(void**)(self + (s << 2) + 0x1348);
    fn_8004EFA8(g_GameGlobal, arg);
    *(bool*)(self + 0x1422) = true;
}
}
