#pragma force_active on
struct PictChat {
    unsigned char padding[8];
    unsigned int : 4;
    unsigned int field : 4;
    unsigned int : 24;
};

extern "C" void fn_73_ACB0(PictChat* self, unsigned int value)
{
    self->field = value;
}
