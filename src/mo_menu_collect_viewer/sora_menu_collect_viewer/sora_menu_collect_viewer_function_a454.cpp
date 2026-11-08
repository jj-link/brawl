#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;

extern "C" {
extern char lbl_6_data_7D8[];
extern u8 lbl_6_data_8F0[];

void* __ct__6gfTaskFPCcQ26gfTask8Categoryiib(void*, const char*, int, int, int, bool);
void fn_800B96E8(void*, int);
void fn_16_3B4(void*);
void* memset(void*, int, unsigned long);
}

extern "C" void* fn_6_A454(u8* self)
{
    __ct__6gfTaskFPCcQ26gfTask8Categoryiib(self, lbl_6_data_7D8, 8, 0xF, 8, true);

    *reinterpret_cast<u32*>(self + 0x74) = 0;
    *reinterpret_cast<void**>(self + 0x3C) = lbl_6_data_8F0;
    *reinterpret_cast<u32*>(self + 0x78) = 0;
    *reinterpret_cast<u32*>(self + 0x7C) = 0;
    fn_800B96E8(self + 0x80, 0xFF);

    *reinterpret_cast<u32*>(self + 0x128) = 7;
    *reinterpret_cast<u32*>(self + 0x12C) = 0xE;
    *reinterpret_cast<u32*>(self + 0x130) = 0;
    *reinterpret_cast<u32*>(self + 0x134) = 0;
    *reinterpret_cast<u32*>(self + 0x138) = 0;
    *reinterpret_cast<u32*>(self + 0x13C) = 0;
    *reinterpret_cast<u32*>(self + 0x140) = 0;
    *reinterpret_cast<u32*>(self + 0x144) = 0;
    *reinterpret_cast<u32*>(self + 0x14C) = 0;
    *reinterpret_cast<u32*>(self + 0x150) = 0;
    *reinterpret_cast<u32*>(self + 0x154) = 0;
    *reinterpret_cast<u32*>(self + 0x158) = 0;
    *reinterpret_cast<u32*>(self + 0x15C) = 0;
    *reinterpret_cast<u32*>(self + 0x160) = 0;
    fn_16_3B4(self + 0x1A4);

    self[0x261] = 0;
    *reinterpret_cast<u32*>(self + 0x264) = 0;
    self[0x2C] &= ~2;

    *reinterpret_cast<u32*>(self + 0x70) = 0;
    *reinterpret_cast<u32*>(self + 0x40) = 0;
    *reinterpret_cast<u32*>(self + 0x44) = 0;
    *reinterpret_cast<u32*>(self + 0x48) = 0;
    *reinterpret_cast<u32*>(self + 0x4C) = 0;
    *reinterpret_cast<u32*>(self + 0x50) = 0;
    *reinterpret_cast<u32*>(self + 0x54) = 0;
    *reinterpret_cast<u32*>(self + 0x58) = 0;
    *reinterpret_cast<u32*>(self + 0x5C) = 0;
    *reinterpret_cast<u32*>(self + 0x60) = 0;
    *reinterpret_cast<u32*>(self + 0x64) = 0;
    *reinterpret_cast<u32*>(self + 0x68) = 0;
    *reinterpret_cast<u32*>(self + 0x6C) = 0;

    memset(self + 0x164, 0, 0x15);
    memset(self + 0x179, 0, 0x29);
    memset(self + 0x238, 0, 0x29);

    return self;
}
