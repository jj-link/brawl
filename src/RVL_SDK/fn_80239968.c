#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;

extern char lbl_80529CF8[];
extern u8 fn_80244B64(u16, int);
extern int fn_803F6150(const void*, const void*, unsigned long);

static inline u8* find_entry(const void* arg0) {
    u32 i;
    u8* p;

    i = 0;
    p = (u8*)lbl_80529CF8 + 0x34;
    while (i < 4) {
        if (p[0x119] != 0 && fn_803F6150(p + 8, arg0, 6) == 0) {
            return p;
        }
        i++;
        p += 0x11C;
    }
    return 0;
}

static inline u16 find_id(const void* arg0) {
    u8* p = find_entry(arg0);

    if (p != 0) {
        return *(u16*)p;
    }
    return 0xFFFF;
}

int fn_80239968(void* arg0) {
    if (fn_80244B64(find_id(arg0), 0x13) == 0) {
        return 3;
    }
    return 0;
}
