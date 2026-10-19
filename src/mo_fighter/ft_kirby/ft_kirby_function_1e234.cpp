#pragma force_active on
struct KirbyData {
    unsigned int padding[2];
    unsigned int : 12;
    unsigned int field : 6;
    unsigned int : 14;
};

extern "C" void fn_96_1E234(KirbyData* self, unsigned int value)
{
    self->field = value;
}
