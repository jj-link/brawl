#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;

extern "C" {
extern const char lbl_21_data_A4[];
extern u8 __vt__20muWifiTimeResultTask[];

void* __ct__6gfTaskFPCcQ26gfTask8Categoryiib(void*, const char*, int, int, int, bool);
void fn_800B96E8(void*, int);
void fn_21_2C0(int*);
void __dt__14gfFileIOHandleFv(void*, int);
void __construct_array(void*, void (*)(void*), void (*)(void*), unsigned long, int);
}

extern "C" void* fn_21_1E4(u8* self)
{
    __ct__6gfTaskFPCcQ26gfTask8Categoryiib(self, lbl_21_data_A4, 8, 0xF, 8, true);

    *reinterpret_cast<u32*>(self + 0x48) = 0;
    *reinterpret_cast<void**>(self + 0x3C) = __vt__20muWifiTimeResultTask;
    *reinterpret_cast<u32*>(self + 0x4C) = 0;
    *reinterpret_cast<u32*>(self + 0x50) = 0;
    *reinterpret_cast<u32*>(self + 0x54) = 0;
    *reinterpret_cast<u32*>(self + 0x60) = 0;
    *reinterpret_cast<u32*>(self + 0x64) = 0;
    *reinterpret_cast<u32*>(self + 0x68) = 0;
    *reinterpret_cast<u32*>(self + 0x6C) = 0;
    *reinterpret_cast<u32*>(self + 0x70) = 0;
    fn_800B96E8(self + 0x74, 0xFF);

    self[0x11C] = 0;
    __construct_array(self + 0x140, (void (*)(void*))fn_21_2C0, (void (*)(void*))__dt__14gfFileIOHandleFv, 4, 5);

    self[0x159] = 0;
    self[0x2C] &= ~2;
    *reinterpret_cast<u32*>(self + 0x40) = 0;
    self[0x154] = 0;
    self[0x155] = 0;
    self[0x156] = 0;
    self[0x157] = 0;
    self[0x158] = 0;

    return self;
}