#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef int s32;

extern u8 lbl_8052D9C0[];
extern u8 fn_8025BBD0(u8 *p, u32 size, s32 arg2, s32 arg3);
extern u8 fn_80257860(u8 *p, u32 size, s32 arg2, s32 arg3, s32 depth);

void *fn_80257724(u8 *arg0, u8 *arg1) {
    u8 *sec;
    u8 *rec;
    u8 *rec4;
    u16 j;
    u16 i;
    u8 *ent;
    u8 *end;

    end = (lbl_8052D9C0 + 0x1224) + *(u16 *)(lbl_8052D9C0 + 0x1222) * 0x298;
    if (arg0 == 0) {
        sec = lbl_8052D9C0 + 0x1224;
    } else {
        sec = arg0 + 0x298;
    }

    while (sec < end) {
        for (i = 0; i < *(u16 *)arg1; i++) {
            rec = arg1 + i * 0x12;
            rec4 = rec + 4;
            ent = sec + 0xC;
            for (j = 0; j < *(u16 *)(sec + 8);) {
                if (ent[0xA] == 3) {
                    if (fn_8025BBD0(*(u8 **)(ent + 4), *(u32 *)ent, (s32)rec4, *(u16 *)(rec + 2))) {
                        break;
                    }
                } else if (ent[0xA] == 6) {
                    if (fn_80257860(*(u8 **)(ent + 4), *(u32 *)ent, (s32)rec4, *(u16 *)(rec + 2), 0)) {
                        break;
                    }
                }
                j++;
                ent += 0xC;
            }
            if (j == *(u16 *)(sec + 8)) {
                break;
            }
        }
        if (i == *(u16 *)arg1) {
            return sec;
        }
        sec += 0x298;
    }
    return 0;
}
