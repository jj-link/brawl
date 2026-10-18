#pragma force_active on
extern "C" unsigned char lbl_119_data_1ED0[];

extern "C" void fn_119_580C(unsigned char *object, unsigned char value)
{
    unsigned char *p = (unsigned char *)&lbl_119_data_1ED0[0 * (int)object];
    *(unsigned char **)object = p;
    object[4] = value;
}
