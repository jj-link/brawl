#pragma force_active on
struct MansionData {
    unsigned int padding[2];
    unsigned int : 2;
    unsigned int flags : 2;
    unsigned int : 28;
};

extern "C" void fn_47_4BA0(MansionData* self, unsigned int value)
{
    self->flags = value;
}
