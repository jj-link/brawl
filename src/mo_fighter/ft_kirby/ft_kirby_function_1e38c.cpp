#pragma force_active on
struct Data {
    unsigned int pad[2];
    unsigned int value;
};

extern "C" int fn_96_1E38C(const Data* self)
{
    return (int)((self->value << 8) & 0xF8000000u) >> 28;
}
