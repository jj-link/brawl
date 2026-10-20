#pragma force_active on
struct Data {
    unsigned int pad[2];
    unsigned int flags;
};

extern "C" unsigned int fn_48_B468(const Data* self)
{
    return (self->flags >> 4) & 1;
}
