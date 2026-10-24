#pragma force_active on
typedef unsigned char u8;
typedef int s32;

struct Slot {
    s32 key;
    s32 cnt;
};

extern "C" s32 fn_80157048(s32 unused, u8* data) {
    Slot slots[7];
    s32 i;
    s32 idx;
    u8 key;
    s32* p;
    s32 val;
    
    for (i = 0; i < 7; i++) {
        slots[i].key = -1;
        slots[i].cnt = 0;
    }
    
    for (i = 0; i < 7; i++) {
        if (data[0x25] <= 1) {
            key = data[0x24];
            p = (s32*)&slots[0].key;
            for (idx = 0; idx < 7; idx++) {
                val = *p;
                if (val < 0) {
                    slots[idx].key = key;
                    slots[idx].cnt = 1;
                    break;
                } else if ((s32)key == val) {
                    slots[idx].cnt++;
                    break;
                }
                p += 2;
            }
        }
        data += 0x2AC;
    }
    
    s32 ret = 0;
    for (i = 0; i < 7; i++) {
        if (slots[i].key >= 0 && ret < slots[i].cnt) {
            ret = slots[idx].cnt;
        }
    }
    return ret;
}
