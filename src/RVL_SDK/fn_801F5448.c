#pragma force_active on
typedef float f32;

typedef struct {
    unsigned char pad0[0x544];
    f32 val0;
    f32 val1;
    f32 val2;
    f32 val3;
    f32 val4;
    f32 val5;
    unsigned char pad1[0x5FC - 0x55C];
    unsigned int flags;
} GXData_t;

extern GXData_t *const __GXData;
extern f32 lbl_805A38D8;

void fn_801F5448(int arg0, f32 f0, f32 f1, f32 f2, f32 f3, f32 f4, f32 f5) {
    if (arg0 == 0) {
        f1 -= lbl_805A38D8;
    }
    __GXData->val0 = f0;
    __GXData->val1 = f1;
    __GXData->val2 = f2;
    __GXData->val3 = f3;
    __GXData->val4 = f4;
    __GXData->val5 = f5;
    __GXData->flags |= 0x10000000;
}
