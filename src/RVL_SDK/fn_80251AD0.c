#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;

typedef struct Entry {
    u8 pad0[0xA4];
} Entry;

extern u8 lbl_8052D5A8[];

Entry *fn_80251AD0(const u8 *arg0, u16 arg1) {
    const u8 *p;
    u8 val;

    if (arg0 == 0) {
        return 0;
    }
    if (arg1 > 0x3d) {
        return 0;
    }
    p = arg0 + arg1;
    val = p[0x24];
    if (val == 0) {
        return 0;
    }
    return (Entry *)(lbl_8052D5A8 + (val - 1) * 0xA4 + 0x68);
}
