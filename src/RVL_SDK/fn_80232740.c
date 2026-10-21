#pragma force_active on
extern void fn_802301F0();
extern void fn_8022FFDC(unsigned char);

typedef struct Obj {
    int unk0;
    unsigned char pad4[0xC];
    unsigned char unk10;
} Obj;

void fn_80232740(Obj *arg0) {
    fn_802301F0();
    if (arg0->unk0 == 0) {
        fn_8022FFDC(arg0->unk10);
    }
}
