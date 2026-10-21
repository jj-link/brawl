#pragma force_active on
extern "C" {
void fn_27_197E94(void* self, unsigned int a, unsigned int b);
void* fn_27_14DFE4(void* p, unsigned int a2, unsigned int a3, unsigned int a4, unsigned int a5, unsigned int a6, unsigned int a7, unsigned int a8, unsigned int a9);
void fn_27_A78C0(void* self);
void fn_27_1991F0(void* p, unsigned int a);
void* fn_27_CAF4C(char* self, unsigned int a);
}

extern "C" void* fn_116_8E58(char* self, unsigned int a2, unsigned int a3, unsigned int a4) {
    fn_27_197E94(self, 1, 0);
    fn_27_14DFE4(self + 0x10, a2, (unsigned char)a3, (unsigned int)(self + 0x220), (unsigned int)(self + 0x94), (unsigned int)(self + 0x78), (unsigned int)self, a4, 8);
    fn_27_A78C0(self + 0x78);
    fn_27_1991F0(self + 0x94, 0);
    fn_27_CAF4C(self + 0x220, 0);
    return self;
}
