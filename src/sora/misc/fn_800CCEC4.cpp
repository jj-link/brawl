#pragma force_active on
extern "C" {
void fn_80146878(void* p, int v);
void fn_801473C4(void);
extern char g_Network[];
}

extern "C" void fn_800CCEC4(char* self) {
    fn_80146878(g_Network, 0);
    *(unsigned int*)(self + 0x1048) = 0;
    *(unsigned int*)(self + 0x104c) = 0;
    fn_801473C4();
}
