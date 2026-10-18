#pragma force_active on
extern "C" {
typedef int s32;
typedef unsigned int u32;

typedef struct Tbl {
    s32 a[9];
} Tbl;

extern const Tbl lbl_41_rodata_DD0;

s32 fn_41_2BAD4(s32 unused, s32 key) {
    Tbl tbl = lbl_41_rodata_DD0;
    u32 i;
    for (i = 0; i < 11; i++) {
        if (i == 9 || i == 10) {
            continue;
        }
        if (key == tbl.a[i]) {
            return i;
        }
    }
    return 9;
}
}
