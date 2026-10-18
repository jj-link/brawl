#pragma force_active on
extern "C" void fn_66_11BBC(unsigned char* object)
{
    int state = object[0x158];
    if (state >= 6)
        return;
    if (state < 2)
        return;
    object[0x160] = 1;
}
