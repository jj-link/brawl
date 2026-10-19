#pragma force_active on
struct KirbyData {
    unsigned char padding[8];
    unsigned int upper : 8;
    unsigned int value : 4;
    unsigned int lower : 20;
};

extern "C" void fn_96_1E2FC(KirbyData* self, unsigned int value)
{
    self->value = value;
}
