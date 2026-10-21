#pragma force_active on
typedef unsigned int u32;
typedef int s32;

typedef struct {
    u32 w0;
    u32 w1;
    u32 w2;
} Entry;

s32 fn_80210A9C(void);

s32 fn_80210EEC(s32 *arg0) {
    Entry *base;
    s32 temp_r3;

    temp_r3 = fn_80210A9C();
    base = (Entry *)arg0[1];
    if (temp_r3 >= 0 && (base[temp_r3].w0 & 0xFF000000)) {
        goto store;
    }
    return 0;
store:
    arg0[6] = temp_r3;
    return 1;
}
