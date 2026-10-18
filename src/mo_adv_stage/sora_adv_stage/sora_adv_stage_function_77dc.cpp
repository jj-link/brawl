#pragma force_active on
extern "C" const float lbl_40_rodata_2C[];

extern "C" float fn_40_77DC(void *self, float x)
{
    unsigned int *entries =
        *(unsigned int **)((char *)self + 0x1D0);

    if (entries != 0) {
        unsigned int count =
            *(unsigned int *)((char *)self + 0x1D4);

        for (unsigned int i = 0; i < count; ++i) {
            unsigned int *candidate =
                *(unsigned int **)((char *)self + 0x524);

            if (*(unsigned int *)((char *)candidate + 0x620) ==
                *(unsigned int *)((char *)entries + i * 16)) {
                return *(float *)((char *)entries + i * 16 + 12);
            }
        }
    }

    return lbl_40_rodata_2C[0];
}
