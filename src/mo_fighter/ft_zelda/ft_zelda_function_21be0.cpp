#pragma force_active on
typedef unsigned char u8;

struct Fn104Accesser {
    u8 prefix[0x14];
    int firstIndex;
    u8 unused[0x20 - 0x18];
    int* rows[1];
};

extern "C" int fn_104_21BE0(Fn104Accesser* self, void* accesser, int index, int element) {
    return self->rows[index - self->firstIndex][element];
}
