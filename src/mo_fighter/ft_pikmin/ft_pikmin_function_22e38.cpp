#pragma force_active on
extern "C" void* fn_113_22E94(void* ptr, short flag);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_113_22E38(void* self, short a1)
{
    if (self != 0) {
        fn_113_22E94(self, 0);
        if (a1 > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
