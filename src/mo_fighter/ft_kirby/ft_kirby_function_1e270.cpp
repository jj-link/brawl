#pragma force_active on
struct KirbyFlags {
    unsigned int padding[2];
    unsigned int upper : 4;
    unsigned int value : 4;
    unsigned int lower : 24;
};

extern "C" void fn_96_1E270(KirbyFlags* self, unsigned int value)
{
    self->value = value;
}
