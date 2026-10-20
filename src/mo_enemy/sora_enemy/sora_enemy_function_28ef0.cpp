#pragma force_active on

struct Destination {
    void* source;
    unsigned char value;
};

struct UnkStruct {
    unsigned char padding[0x1C];
    Destination* array;
    unsigned char pad2[4];
    int count;
};

extern "C" unsigned fn_41_28DC8(UnkStruct* self, int value);
extern "C" void fn_41_2A4E0(Destination* self);

extern "C" void fn_41_28EF0(UnkStruct* self, int index) {
    if (fn_41_28DC8(self, index) == 1)
        return;
    if (index == -1) {
        for (int i = 0; i < self->count; i++)
            fn_41_2A4E0(&self->array[i]);
    } else {
        fn_41_2A4E0(&self->array[index]);
    }
}
