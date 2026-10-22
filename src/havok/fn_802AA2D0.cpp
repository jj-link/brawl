#pragma force_active on
struct T { char pad[8]; int u8; char pad2[8]; int u14; char pad3[16]; int u28; };
extern T* lbl_805A0EB8;

extern "C" int fn_802AA2D0(void) {
    T* t = lbl_805A0EB8;
    int b = t->u28 + t->u14;
    if (t->u8 <= b) {
        return 0;
    }
    return t->u8 - b;
}
