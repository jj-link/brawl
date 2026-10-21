#pragma force_active on
typedef unsigned int u32;

extern "C" {
void* fn_27_197E94(void*, u32, u32);
void* fn_27_14DFE4(void*, u32, u32, u32, u32, u32, u32, u32, u32);
void fn_27_A78C0(void*);
void fn_27_1991F0(void*, u32);
void* fn_27_CAF4C(void*, u32);

void* fn_91_8290(void* self, u32 a2, u32 a3, u32 a4) {
    fn_27_197E94(self, 1, 0);
    fn_27_14DFE4(static_cast<char*>(self) + 0x10, a2, a3 & 0xff,
                 static_cast<u32>(reinterpret_cast<unsigned long>(self) + 0x220),
                 static_cast<u32>(reinterpret_cast<unsigned long>(self) + 0x94),
                 static_cast<u32>(reinterpret_cast<unsigned long>(self) + 0x78),
                 static_cast<u32>(reinterpret_cast<unsigned long>(self)), a4, 8);
    fn_27_A78C0(static_cast<char*>(self) + 0x78);
    fn_27_1991F0(static_cast<char*>(self) + 0x94, 0);
    fn_27_CAF4C(static_cast<char*>(self) + 0x220, 0);
    return self;
}
}
