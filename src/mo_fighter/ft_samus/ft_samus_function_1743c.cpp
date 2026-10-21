#pragma force_active on
typedef unsigned int u32;
typedef unsigned char u8;

extern "C" {
void* fn_27_197E94(void* self, u32 mode, u32 flag);
void* fn_27_14DFE4(void* p, u32 a2, u8 a3, void* a4, void* a5, void* a6, void* a7, u32 a8, u32 a9);
void fn_27_A78C0(void* self);
void fn_27_1991F0(void* p, u32 mode);
char* fn_27_CA114(char* self, u32 mode);

char* fn_94_1743C(char* self, u32 a2, u32 a3, u32 a4) {
    fn_27_197E94(self, 1, 0);
    fn_27_14DFE4(self + 0x10, a2, (u8)a3, self + 0x220, self + 0x94, self + 0x78, self, a4, 8);
    fn_27_A78C0(self + 0x78);
    fn_27_1991F0(self + 0x94, 0);
    fn_27_CA114(self + 0x220, 0);
    return self;
}
}
