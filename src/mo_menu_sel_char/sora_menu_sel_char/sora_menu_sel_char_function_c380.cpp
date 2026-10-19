#pragma force_active on
extern "C" const int lbl_10_rodata_304[9];

struct Menu {
    unsigned char padding[0x138];
    int value;
};

extern "C" int fn_10_C380(Menu* self)
{
    int value = self->value;
    int i;
    for (i = 0; i < 9; ++i) {
        if (lbl_10_rodata_304[i] >= value)
            break;
    }
    return i;
}
