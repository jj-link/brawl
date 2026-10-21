#pragma force_active on
struct FnObj {
    char pad[0xAF];
    unsigned char unkAF;
    unsigned char unkB0;
    unsigned char unkB1;
};

extern "C" void fn_801D1210(FnObj* obj, unsigned char val) {
    if (obj->unkAF != val) {
        obj->unkAF = val;
        obj->unkB1 |= 0x2;
    }
}
