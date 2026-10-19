#pragma force_active on
extern "C" void fn_65_68BC(unsigned char *arg0, unsigned char arg1, int arg2, float arg3)
{
    arg0[0x184] = arg1;
    *(int *)(arg0 + 0x188) = arg2;
    *(float *)(arg0 + 0x18c) = arg3;
}
