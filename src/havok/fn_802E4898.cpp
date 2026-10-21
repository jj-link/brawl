#pragma force_active on
extern "C" void fn_802E4338(void);
extern char lbl_80488020[];
extern float lbl_805A43C0;

struct HavokObj {
    char* vtable;
    unsigned char pad4[4];
    unsigned char unk8;
    unsigned char pad9[0xC7];
    float unkD0;
    float unkD4;
    float unkD8;
    float unkDC;
};

extern "C" HavokObj* fn_802E4898(HavokObj* arg0) {
    float zero;
    fn_802E4338();
    zero = lbl_805A43C0;
    arg0->vtable = lbl_80488020;
    arg0->unkD0 = zero;
    arg0->unkD4 = zero;
    arg0->unkD8 = zero;
    arg0->unkDC = zero;
    arg0->unk8 = 4;
    return arg0;
}
