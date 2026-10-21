#pragma force_active on
struct Object {
    unsigned char pad[0x94];
    unsigned int value;
};

struct State {
    unsigned char pad[0x9C];
    Object* object;
};

extern "C" State lbl_27_bss_3210;

extern "C" unsigned int fn_27_148330() {
    return lbl_27_bss_3210.object->value;
}
