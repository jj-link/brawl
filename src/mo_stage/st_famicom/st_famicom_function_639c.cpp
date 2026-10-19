#pragma force_active on
struct FnStruct68 {
    unsigned char pad[8];
    int count;
};

extern "C" void* fn_68_639C(FnStruct68* self, int index) {
    int i = (self->count >> 30) + index;
    if (i >= 1) {
        i = i - 1;
    }
    return (char*)self + i * 0x38 + 0xc;
}
