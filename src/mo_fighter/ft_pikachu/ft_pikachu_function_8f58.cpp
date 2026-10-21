#pragma force_active on
typedef unsigned int u32;

extern "C" {
void* fn_27_197E94(char* self, u32 a, u32 b);
void fn_27_A78C0(char* self);
void fn_27_1991F0(char* self, u32 a);
void* fn_27_14DFE4(char* p, void* a2, u32 a3, void* a4, void* a5, void* a6, void* a7, void* a8, u32 a9);
void* fn_27_CAF4C(char* self, u32 a);

char* fn_98_8F58(char* self, char* a2, u32 a3, char* a4) {
    fn_27_197E94(self, 1, 0);
    fn_27_14DFE4(self + 0x10, a2, a3 & 0xFF, self + 0x220, self + 0x94, self + 0x78, self, a4, 8);
    fn_27_A78C0(self + 0x78);
    fn_27_1991F0(self + 0x94, 0);
    fn_27_CAF4C(self + 0x220, 0);
    return self;
}
}