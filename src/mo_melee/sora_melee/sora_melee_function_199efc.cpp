#pragma force_active on
extern "C" {
struct Obj {
    unsigned char pad[8];
    unsigned int field;
};

int fn_27_199EFC(Obj* p) {
    return ((int)((p->field >> 19) & 0x1F) << 27) >> 28;
}
}
