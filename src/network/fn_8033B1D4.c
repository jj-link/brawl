#pragma force_active on
typedef int s32;

typedef struct {
    char pad[0x24];
    s32 unk24;
    s32 unk28;
    char pad2[0x78 - 0x2C];
    void (*func)(s32, s32, s32);
    s32 arg;
} Obj;

extern Obj *lbl_805A0F88;

void fn_8033B1D4(s32 arg0, s32 arg1) {
    s32 v = lbl_805A0F88->unk28;
    if (v != 4) {
        s32 t = lbl_805A0F88->unk24;
        lbl_805A0F88->unk28 = t;
        lbl_805A0F88->unk24 = v;
    }
    lbl_805A0F88->func(arg0, arg1, lbl_805A0F88->arg);
}
