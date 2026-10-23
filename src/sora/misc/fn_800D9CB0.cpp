#pragma force_active on
typedef unsigned char u8;

extern "C" u8 fn_800C851C(void);
extern "C" u8 fn_800C8548(void);

extern "C" void* fn_800D9CB0(void* arg0) {
    u8 idx = fn_800C8548();
    if (idx == 0xFF) {
        idx = fn_800C851C();
        if (idx == 0xFF) {
            idx = 4;
        }
        return (u8*)((int)arg0 + idx * 0x218 + 0x70);
    }

    int addr = (int)arg0 + idx * 0x218;
    u8* p = (u8*)(addr + 0x70);
    if (!((p[0x78] >> 7) & 1)) {
        idx = fn_800C851C();
        if (idx == 0xFF) {
            idx = 4;
        }
        p = (u8*)((int)arg0 + idx * 0x218 + 0x70);
    }
    return p;
}
