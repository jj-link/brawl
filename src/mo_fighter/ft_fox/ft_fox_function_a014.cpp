#pragma force_active on
extern "C" void *fn_97_9F28(void *obj, int a);

extern "C" void *fn_97_A014(void *obj, int a)
{
    switch (a)
    {
        case 0:
            return obj;
        case 1:
            return (char *)obj + 0x48c;
        case 2:
            return fn_97_9F28(obj, a);
        default:
            return fn_97_9F28(obj, a);
    }
}