#pragma force_active on
struct Fn54_5BACData {
    unsigned char padding[8];
    int value;
};

extern "C" int fn_54_5BAC(const Fn54_5BACData* self) {
    return self->value >> 30;
}
