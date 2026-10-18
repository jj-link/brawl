#pragma force_active on
struct HalberdData {
    unsigned int padding[2];
    unsigned int flags;
};

extern "C" unsigned int fn_57_A764(const HalberdData* self)
{
    return (self->flags >> 22) & 1;
}
