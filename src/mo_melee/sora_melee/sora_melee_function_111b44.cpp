#pragma force_active on
struct InnerData {
    unsigned char padding[0x4D4];
    float value;
};

struct Holder {
    InnerData* data;
    float get() { return data->value; }
};

extern "C" float fn_27_111B44(Holder* self) {
    return self->get();
}
