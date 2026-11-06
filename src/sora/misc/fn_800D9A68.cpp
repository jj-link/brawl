#pragma force_active on

typedef unsigned char u8;
typedef unsigned int u32;

extern "C" u8 fn_800C851C(void);
extern "C" u8 fn_800C8548(void);

extern "C" u8 fn_800D9A68(void* arg0) {
    u8 idx = fn_800C8548();
    int base = (idx == 0xFF) ? 0 : (int)arg0 + idx * 0x218 + 0x70;
    if (base == 0) {
        return 0;
    }
    u8 result = 0;
    u32 i = 0;
    do {
        u8 idx2 = fn_800C8548();
        u8* q;
        if (idx2 == 0xFF) {
            u8 loc = fn_800C851C();
            if (loc == 0xFF) {
                loc = 4;
            }
            q = (u8*)arg0 + loc * 0x218 + 0x70;
        } else {
            q = (u8*)((int)arg0 + idx2 * 0x218 + 0x70);
            if (!((q[0x78] >> 7) & 1)) {
                u8 loc = fn_800C851C();
                if (loc == 0xFF) {
                    loc = 4;
                }
                q = (u8*)arg0 + loc * 0x218 + 0x70;
            }
        }
        if ((int)q[0x68 + (u8)i] == 1) {
            result |= 1 << (u8)i;
        }
        i++;
    } while (i < 4);
    return result;
}
