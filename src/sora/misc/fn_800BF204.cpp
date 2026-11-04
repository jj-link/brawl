#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;

extern "C" {
extern char lbl_80456D30[];
extern u8 lbl_80456D54[];

void* __ct__6gfTaskFPCcQ26gfTask8Categoryiib(void*, const char*, int, int, int, bool);
void fn_800B96E8(void*, int);
}

extern "C" void* fn_800BF204(u8* self)
{
    __ct__6gfTaskFPCcQ26gfTask8Categoryiib(self, lbl_80456D30, 8, 0xF, 8, true);

    *reinterpret_cast<u32*>(self + 0x44) = 0;
    *reinterpret_cast<void**>(self + 0x3C) = lbl_80456D54;
    *reinterpret_cast<u32*>(self + 0x48) = 0;
    *reinterpret_cast<u32*>(self + 0x4C) = 0;
    *reinterpret_cast<u32*>(self + 0x50) = 0;
    fn_800B96E8(self + 0x54, 0xFF);

    *reinterpret_cast<u32*>(self + 0xFC) = 0;
    self[0x100] = 1;
    *reinterpret_cast<u32*>(self + 0x104) = 0;
    *reinterpret_cast<u32*>(self + 0x108) = 4;
    *reinterpret_cast<u32*>(self + 0x10C) = 0;
    *reinterpret_cast<u32*>(self + 0x110) = 0;
    *reinterpret_cast<u32*>(self + 0x114) = 0;
    *reinterpret_cast<u32*>(self + 0x118) = 0;
    *reinterpret_cast<u32*>(self + 0x11C) = 0;
    self[0x120] = 0;
    *reinterpret_cast<u32*>(self + 0x124) = 0;
    *reinterpret_cast<u32*>(self + 0x128) = 5;
    self[0x2C] &= ~2;

    *reinterpret_cast<u32*>(self + 0x40) = 0;

    return self;
}