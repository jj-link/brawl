#pragma force_active on
typedef unsigned int u32;
typedef unsigned char u8;

extern "C" {
void* fn_27_197E94(void* self, u32 mode, u32 flag);
void* fn_27_14DFE4(void* p, u32 a2, u32 a3, void* a4, void* a5, void* a6, void* a7, u32 a8, u32 a9);
void fn_27_A78C0(void* self);
void fn_27_1991F0(void* p, u32 v);
void* fn_27_CAF4C(void* self, u32 v);
}

extern "C" void* fn_123_876C(char* self, u32 a, u8 b, u32 c) {
    fn_27_197E94(self, 1, 0);
    fn_27_14DFE4(self + 0x10, a, (u32)b, self + 0x220, self + 0x94,
                 self + 0x78, self, c, 8);
    fn_27_A78C0(self + 0x78);
    fn_27_1991F0(self + 0x94, 0);
    fn_27_CAF4C(self + 0x220, 0);
    return self;
}
