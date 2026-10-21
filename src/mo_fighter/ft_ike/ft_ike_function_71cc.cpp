#pragma force_active on
extern "C" {
void* fn_27_197E94(void* self, unsigned int a, unsigned int b);
void* fn_27_14DFE4(void* p, unsigned int a2, unsigned char a3, void* a4, void* a5, void* a6, void* a7, unsigned int a8, unsigned int a9);
void fn_27_A78C0(void* self);
void fn_27_1991F0(void* p, unsigned int v);
void* fn_27_CAF4C(void* p, unsigned int v);
}

extern "C" void* fn_119_71CC(char* self, unsigned int a1, unsigned int a2, unsigned int a3) {
    unsigned int val = 8;
    fn_27_197E94(self, 1, 0);
    fn_27_14DFE4(self + 0x10, a1, (unsigned char)a2, self + 0x220, self + 0x94, self + 0x78, self, a3, val);
    fn_27_A78C0(self + 0x78);
    fn_27_1991F0(self + 0x94, 0);
    fn_27_CAF4C(self + 0x220, 0);
    return self;
}
