#pragma force_active on
typedef unsigned int u32;
typedef int s32;
typedef float f32;

struct Entry {
    s32 id;
    u32 bits;
};

extern "C" char* lbl_27_bss_5668;

extern "C" int fn_96_E18C(char* arg0, char* arg1) {
    char* p = *(char**)(arg0 + 0x1B678);
    Entry* tbl;
    u32 count;
    u32 i;

    count = *(u32*)(p + 0x188);
    if (count > 0x35) {
        return 0;
    }

    tbl = *(Entry**)(p + 0x184);
    if (tbl == 0) {
        return 0;
    }

    for (i = 0; i < count; i++) {
        Entry e = tbl[i];
        if (e.id < 0 || e.id > 0x35) {
            return 0;
        }
        if (e.id == *(s32*)(lbl_27_bss_5668 + 0x44)) {
            if (*(f32*)(arg1 + 4) <= *(f32*)&e.bits) {
                return 1;
            }
        }
    }
    return 0;
}
