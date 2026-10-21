#pragma force_active on
typedef int s32;

typedef struct {
    char pad[0x90];
    s32 unk90;
    s32 unk94;
} Obj;

extern Obj *lbl_805A0F88;

s32 fn_8033A50C(s32 arg0, s32 arg1) {
    if (lbl_805A0F88 == 0) {
        return 0;
    }
    lbl_805A0F88->unk90 = arg0;
    lbl_805A0F88->unk94 = arg1;
    return 1;
}
