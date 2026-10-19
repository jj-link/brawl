#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;

extern "C" {
extern const char lbl_2_data_4B08[];
extern u8 lbl_2_data_4C90[];

void* __ct__6gfTaskFPCcQ26gfTask8Categoryiib(void*, const char*, int, int, int, bool);
void fn_800B96E8(void*, int);
void fn_16_3B4(void*);
}

extern "C" void* fn_2_385C0(u8* self)
{
    __ct__6gfTaskFPCcQ26gfTask8Categoryiib(self, lbl_2_data_4B08, 8, 15, 8, true);

    *reinterpret_cast<u32*>(self + 0x40) = 0;
    *reinterpret_cast<void**>(self + 0x3C) = lbl_2_data_4C90;
    *reinterpret_cast<u32*>(self + 0x70) = 0;
    *reinterpret_cast<u32*>(self + 0x74) = 0;
    fn_800B96E8(self + 0x78, 255);

    *reinterpret_cast<u32*>(self + 0x120) = 0;
    self[0x124] = 1;
    *reinterpret_cast<u32*>(self + 0x128) = 0;
    *reinterpret_cast<u32*>(self + 0x12C) = 0;
    *reinterpret_cast<u32*>(self + 0x130) = 0;
    self[0x134] = 0;
    *reinterpret_cast<u32*>(self + 0x138) = 2;
    *reinterpret_cast<u32*>(self + 0x13C) = 13;
    *reinterpret_cast<u32*>(self + 0x140) = 0;
    *reinterpret_cast<u32*>(self + 0x148) = 0;
    fn_16_3B4(self + 0x14C);

    *reinterpret_cast<u32*>(self + 0x1E0) = 0;
    *reinterpret_cast<u32*>(self + 0x1E4) = 0;
    *reinterpret_cast<u32*>(self + 0x1E8) = 0;
    *reinterpret_cast<u32*>(self + 0x1EC) = 0;
    self[0x1F0] = 0;
    self[0x1F1] = 0;
    self[0x2C] &= ~2;

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

    return self;
}
