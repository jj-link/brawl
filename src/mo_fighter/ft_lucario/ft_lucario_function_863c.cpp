#pragma force_active on
struct FnWork;

extern "C" void* fn_27_197E94(void* self, unsigned int mode, unsigned int flag);
extern "C" void* fn_27_14DFE4(void* p, unsigned int a2, unsigned int a3, unsigned int a4, unsigned int a5, unsigned int a6, unsigned int a7, unsigned int a8, unsigned int a9);
extern "C" void fn_27_A78C0(void* self);
extern "C" void fn_27_1991F0(void* p, unsigned int mode);
extern "C" void* fn_27_CAF4C(void* self, unsigned int mode);

extern "C" void* fn_118_863C(unsigned char* self, unsigned int a2, unsigned char a3, unsigned int a4) {
    fn_27_197E94(self, 1, 0);
    fn_27_14DFE4(self + 0x10, a2, (unsigned char)a3, (unsigned int)(self + 0x220), (unsigned int)(self + 0x94), (unsigned int)(self + 0x78), (unsigned int)self, a4, 8);
    fn_27_A78C0(self + 0x78);
    fn_27_1991F0(self + 0x94, 0);
    fn_27_CAF4C(self + 0x220, 0);
    return self;
}
