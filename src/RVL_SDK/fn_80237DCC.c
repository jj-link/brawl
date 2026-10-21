#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;
typedef int s32;

typedef struct {
    u8 count;
    u8 pad[3];
    u8 *table;
} SomeTable;

extern SomeTable *lbl_8059EDC8;

s32 fn_80237DCC(u8 *arg0, u32 arg1) {
    SomeTable *t = lbl_8059EDC8;
    u8 i;
    u32 key = (arg1 >> 2) & 0x3F;

    for (i = 0; i < t->count; i++) {
        u32 off = (u32)i * 2;
        if (key == lbl_8059EDC8->table[off & 0x1FE]) {
            arg0[0x15] = (lbl_8059EDC8->table + (off & 0x1FE))[1];
            return 1;
        }
    }
    return 0;
}
