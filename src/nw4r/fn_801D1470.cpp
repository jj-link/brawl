#pragma force_active on

extern "C" float lbl_805A3640;
extern "C" float lbl_805A3644;

struct FnObj {
    unsigned char pad[0xB1];
    unsigned char flags;
    unsigned char pad2[0x16];
    float value;
};

extern "C" void fn_801D1470(FnObj *obj, float farg) {
    float v;
    if (farg > lbl_805A3640) {
        v = lbl_805A3640;
    } else {
        if (farg < lbl_805A3644) {
            v = lbl_805A3644;
        } else {
            v = farg;
        }
    }
    if (v != obj->value) {
        obj->value = v;
        obj->flags |= 0x10;
    }
}
