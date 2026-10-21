#pragma force_active on
struct MansionData {
    unsigned char padding[8];
    unsigned int flags : 4;
    unsigned int remaining : 28;
};

extern "C" void fn_47_4F08(MansionData* self, unsigned int value)
{
    self->flags = value;
}
