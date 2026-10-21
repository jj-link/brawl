#pragma force_active on
extern "C" {
extern char lbl_27_bss_8094[];
extern void* g_ftManager;
extern void fn_27_35896C(void* a, void* b, void* c, unsigned char d, unsigned char e);
extern int getConstantInt__15soValueAccesserFP16soModuleAccesserUlUl(void* a, unsigned long b, unsigned long c);
extern void fn_27_10D968(void* a, void* b, int c, int d, int e, void* f);
extern void fn_27_130D64(void* p);

void fn_110_1F0D8(void* object) {
    char* base = (char*)object;
    unsigned char zero = 0;
    fn_27_35896C(lbl_27_bss_8094, *(void**)(base + 0x60), *(void**)(base + 0x10c), zero, zero);
    void* f10c = *(void**)(base + 0x10c);
    void* manager = g_ftManager;
    int value = getConstantInt__15soValueAccesserFP16soModuleAccesserUlUl(*(void**)(base + 0x60), 0x5a38, 0);
    fn_27_10D968(manager, f10c, 6, value, 0, *(void**)(base + 0x28));
    fn_27_130D64(object);
}
}
