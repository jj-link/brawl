#pragma force_active on
extern "C" {
void* fn_27_197E94(void*, unsigned int, unsigned int);
void* fn_27_14DFE4(void*, unsigned int, unsigned int, void*, void*, void*, void*, void*, unsigned int);
void fn_27_A78C0(void*);
void fn_27_1991F0(void*, unsigned int);
void* fn_27_CA550(void*, unsigned int);
}

extern "C" void* fn_96_99F4(void* self, void* a2, unsigned int a3, void* a4) {
    char* p = (char*)self;
    fn_27_197E94(self, 1, 0);
    fn_27_14DFE4(p + 0x10, (unsigned int)a2, a3 & 0xFF,
                 p + 0x220, p + 0x94, p + 0x78, p, a4, 8);
    fn_27_A78C0(p + 0x78);
    fn_27_1991F0(p + 0x94, 0);
    fn_27_CA550(p + 0x220, 0);
    return self;
}
