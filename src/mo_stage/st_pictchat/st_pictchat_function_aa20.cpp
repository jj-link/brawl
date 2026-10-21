#pragma force_active on
struct PictChat {
    unsigned int padding[2];
    unsigned int : 4;
    unsigned int value : 4;
    unsigned int : 24;
};

extern "C" void fn_73_AA20(PictChat* self, unsigned int value)
{
    self->value = value;
}
