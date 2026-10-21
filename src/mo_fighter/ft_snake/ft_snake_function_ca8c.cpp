#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;

extern "C" void* fn_27_197E94(void* self, u32 mode, u32 flag);
extern "C" void* fn_27_14DFE4(void* p, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7, u32 a8, u32 a9);
extern "C" void fn_27_A78C0(void* self);
extern "C" void fn_27_1991F0(void* p, u32 v);
extern "C" void* fn_27_CAF4C(void* self, u32 v);

extern "C" void* fn_122_CA8C(char* self, u32 a, u8 b, u32 c) {
    fn_27_197E94(self, 1, 0);
    fn_27_14DFE4(self + 0x10, a, b, (u32)(self + 0x220), (u32)(self + 0x94), (u32)(self + 0x78), (u32)self, c, 8);
    fn_27_A78C0(self + 0x78);
    fn_27_1991F0(self + 0x94, 0);
    fn_27_CAF4C(self + 0x220, 0);
    return self;
}
