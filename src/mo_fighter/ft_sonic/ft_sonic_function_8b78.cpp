#pragma force_active on
extern "C" void* fn_123_8A8C(void*);

extern "C" void* fn_123_8B78(void* self, int mode)
{
    switch (mode)
    {
    case 0:
        return self;
    case 1:
        return (char*)self + 0x4A8;
    case 2:
        return fn_123_8A8C(self);
    default:
        return fn_123_8A8C(self);
    }
}
