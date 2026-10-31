#pragma force_active on
extern "C" void *fn_92_8B18(void *);

extern "C" void *fn_92_8C04(void *arg0, int arg1)
{
    switch (arg1)
    {
    case 0:
        return arg0;
    case 1:
        return (char *)arg0 + 0x4E0;
    case 2:
        return fn_92_8B18(arg0);
    default:
        return fn_92_8B18(arg0);
    }
}
