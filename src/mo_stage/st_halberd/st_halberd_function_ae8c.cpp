#pragma force_active on
struct HalberdData {
    unsigned int unknown[2];
    unsigned int flags;
};

extern "C" unsigned int fn_57_AE8C(const HalberdData* self) {
    return (self->flags >> 19) & 1;
}
