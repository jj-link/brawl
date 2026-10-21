#pragma force_active on
struct PictChat {
    unsigned char padding[8];
    unsigned int reserved : 3;
    unsigned int flags : 3;
    unsigned int remaining : 26;
};

extern "C" void fn_73_AB50(PictChat* self, unsigned int value)
{
    self->flags = value;
}
