#pragma force_active on
struct Fn483EFCData {
    unsigned int padding[2];
    unsigned int flags;
};

extern "C" unsigned int fn_48_3EFC(const Fn483EFCData* self) {
    return (self->flags >> 19) & 1u;
}
