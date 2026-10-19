#pragma force_active on
struct KirbyData {
    unsigned int padding[2];
    unsigned int reserved : 8;
    unsigned int value : 4;
    unsigned int remaining : 20;
};

extern "C" void fn_96_1E3C4(KirbyData* self, unsigned int value)
{
    self->value = value;
}
