#pragma force_active on
struct NorfairState {
    unsigned char padding[0x178];
    unsigned char flag;
};

extern "C" void fn_54_1C24(NorfairState* object) {
    object->flag = 0;
}
