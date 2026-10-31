#pragma force_active on
extern "C" void* fn_108_9DF8(void);

extern "C" void* fn_108_9EE4(void* base, int arg)
{
    switch (arg)
    {
        case 0:
            return base;
        case 1:
            return (void*)((char*)base + 0x480);
        case 2:
            return fn_108_9DF8();
        default:
            return fn_108_9DF8();
    }
}
