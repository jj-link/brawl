#pragma force_active on
struct JungleData {
    unsigned int padding[2];
    unsigned int reserved : 4;
    unsigned int value : 4;
    unsigned int remaining : 24;
};

extern "C" void fn_51_6874(JungleData* self, unsigned int value)
{
    self->value = value;
}
