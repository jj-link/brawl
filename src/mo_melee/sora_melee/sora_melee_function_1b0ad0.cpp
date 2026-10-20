#pragma force_active on
struct Data {
    int unk0;
    int unk4;
    int flags;
    int entries[1];
};

extern "C" int* fn_27_1B0AD0(Data* self, unsigned int index) {
    int adjusted = (self->flags >> 30) + index;
    if (adjusted >= 1)
        --adjusted;
    return &self->entries[adjusted];
}
