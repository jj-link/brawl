#pragma force_active on
typedef unsigned int u32;
typedef int s32;

extern unsigned char lbl_80494EE8[];

extern "C" void fn_800257FC(s32 arg0, u32 arg1) {
    u32* p;
    unsigned char* base = lbl_80494EE8 + arg0 * 0x68;
    u32* arr;
    u32 n = *(u32*)(base + 4);
    arr = (u32*)(base + 8);
    s32 i = 0;
    u32* q = arr;

    for (; i < n; ++i) {
        if (q[1] == arg1) {
            p = arr + i * 2;
            for (s32 j = i; j < n - 1; ++j) {
                p[0] = p[2];
                p[1] = p[3];
                p += 2;
            }
            if (i < n - 1) {
                p = arr + n * 2;
                p[-2] = 0;
                p[-1] = 0;
            }
            --*(u32*)(base + 4);
            return;
        }
        q += 2;
    }
}
