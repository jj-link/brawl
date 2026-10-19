#pragma force_active on
extern "C" void fn_66_29AC(char *base, void **outA, void **outB, int type)
{
    if (type == 0x4d) {
        *outA = base + 0x308;
        *outB = base + 0x288;
    }
}
