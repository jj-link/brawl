#pragma force_active on
typedef int s32;
typedef unsigned int u32;

void *fn_803C42AC(void);
s32 fn_803C42D8(void *p);
s32 fn_803C9ED8(s32 a, s32 b);

s32 fn_803C8014(s32 unused, s32 arg1) {
    s32 result;
    void *p = fn_803C42AC();
    result = -1;
    if (p != 0) {
        u32 *q = *(u32 **)p;
        if (q != 0) {
            if (q[2] == 0) {
                s32 r = fn_803C42D8(p);
                if (r != -1) {
                    result = fn_803C9ED8(r, arg1);
                }
            } else {
                result = 0;
            }
        }
    }
    return result;
}
