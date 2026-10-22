#pragma force_active on
typedef unsigned char u8;
typedef int s32;

typedef struct Obj {
    u8 pad0[4];
    s32 unk4;
    u8 pad8[0xC];
    s32 unk14;
} Obj;

extern s32 fn_8020CAD4(void);
extern s32 fn_8020CAEC(void);
extern s32 fn_8020B3D8(s32, s32, Obj *, s32, s32);

s32 fn_8020B668(s32 arg0, s32 arg1, s32 arg2, Obj *arg3) {
    if (fn_8020CAD4() == 0) {
        return -0x80;
    }
    arg3->unk4 = arg2;
    arg3->unk14 = arg1;
    fn_8020B3D8(arg0, arg1, arg3, 1, 1);
    return fn_8020CAEC();
}
