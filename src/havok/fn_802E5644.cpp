#pragma force_active on

extern "C" void fn_802E4338(void);

extern char lbl_80488100[];
extern const float lbl_805A43D0;

struct HavokObj {
    char* vtable;
    unsigned char pad4[4];
    unsigned char unk8;
    unsigned char pad9[0xC7];
    float unkD0;
    float unkD4;
    float unkD8;
    float unkDC;
    unsigned char padE0[0x20];
    int unk100;
    int unk104;
};

extern "C" HavokObj* fn_802E5644(HavokObj* arg0) {
    float zero;
    fn_802E4338();
    zero = lbl_805A43D0;
    arg0->vtable = lbl_80488100;
    arg0->unk100 = 0;
    arg0->unk104 = 0;
    arg0->unkDC = zero;
    arg0->unkD8 = zero;
    arg0->unkD4 = zero;
    arg0->unkD0 = zero;
    arg0->unk8 = 6;
    return arg0;
}
