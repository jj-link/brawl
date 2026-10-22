#pragma force_active on
typedef unsigned char u8;
typedef int s32;

typedef struct Fn20B9Obj {
    s32 unk0;
    u8 pad4[0x8A - 0x4];
    u8 unk8A;
} Fn20B9Obj;

s32 fn_8020B8A8(s32, s32, s32, s32, s32);
s32 fn_8020CAD4(void);
s32 fn_8020CAEC(void);

s32 fn_8020B9BC(s32 arg0, Fn20B9Obj *arg1, s32 arg2) {
    s32 temp_r3;

    if (fn_8020CAD4() == 0) {
        return -0x80;
    }
    temp_r3 = fn_8020B8A8(arg0, arg2, 0, 0, 0);
    if (temp_r3 >= 0) {
        arg1->unk0 = temp_r3;
        arg1->unk8A = 1;
        return 0;
    }
    return fn_8020CAEC();
}
