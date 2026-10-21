#pragma force_active on
struct Data {
    unsigned int unk0;
    unsigned int unk4;
    unsigned int : 6;
    signed int value : 6;
    unsigned int : 20;
};

extern "C" int fn_40_1E41C(const Data* self) {
    return self->value;
}
