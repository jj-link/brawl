#pragma force_active on
typedef unsigned int u32;
typedef int s32;

extern void fn_803F602C(s32 dest, s32 src, s32 count);

void fn_803738B8(s32 *self, s32 arg1, s32 arg2) {
    s32 off = arg1;
    s32 tmp;
    if (arg1 == -1) {
        off = self[2] - arg2;
    }
    tmp = self[0] + off;
    fn_803F602C(tmp, tmp + arg2, (self[2] - off) - arg2);
    self[2] = self[2] - arg2;
}
