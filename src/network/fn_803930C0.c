#pragma force_active on
#pragma optimization_level 1
typedef unsigned int u32;
typedef signed int s32;

typedef struct T { unsigned int unk0; unsigned int unk4; unsigned int unk8; unsigned int unkC; } T;
typedef struct S { unsigned char pad[0x2C]; T *unk2C; } S;
typedef struct A { unsigned char pad[0xC]; S *unkC; } A;

extern int fn_80397580(s32);
extern A **fn_80397570(s32);
extern int *fn_80397568(s32);
extern void fn_8039094C(s32);
extern void fn_80390950(s32);

s32 fn_803930C0(s32 arg0, s32 *arg1, s32 *arg2) {
    s32 r31;
    A *r30;
    s32 ret;
    s32 v;

    r31 = fn_80397580(arg0);
    r30 = *fn_80397570(arg0);
    *arg1 = 0;
    *arg2 = 0;
    fn_8039094C(r31);
    if (r30 != 0) {
        if (r30->unkC->unk2C->unkC != 0) {
            *arg1 = r30->unkC->unk2C->unk4;
            if ((u32)(r30->unkC->unk2C->unkC + 0x10000) == 0xFFFF) {
                v = 0;
            } else {
                v = r30->unkC->unk2C->unkC;
            }
            *arg2 = v;
        }
        ret = 1;
    } else {
        ret = *fn_80397568(arg0) != 0;
    }
    fn_80390950(r31);
    return ret;
}
