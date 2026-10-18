#pragma force_active on
extern "C" void __dl__FPv(void*);

extern "C" void* fn_72_2F7C(void* self, int flag)
{
    if (self != 0) {
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
