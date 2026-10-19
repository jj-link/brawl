#pragma force_active on
struct MansionData {
    unsigned int padding[2];
    unsigned int flags;
};

extern "C" unsigned int fn_47_4234(const MansionData* self)
{
    return (self->flags >> 25) & 1;
}
