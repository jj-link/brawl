#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Entry {
    u32 key;
    u8 pad[0x294];
} Entry;

extern u8 lbl_8052D9C0[];

Entry* fn_80257938(u32 arg0) {
    u8* base = lbl_8052D9C0;
    u32 n = *(u16*)(base + 0x1222);
    Entry* start = (Entry*)(base + 0x1224);
    u32 end0 = (u32)base + n * 0x298;
    Entry* end = (Entry*)(end0 + 0x1224);
    u32 count = (end0 + 0x1224 + 0x297 - (u32)start) / 0x298;
    Entry* p;
    for (p = start; p < end; p++) {
        if (p->key == arg0)
            return p;
    }
    return 0;
}
