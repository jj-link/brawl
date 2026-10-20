#pragma force_active on
#pragma scheduling off

extern "C" void __dl__FPv(void*);

extern "C" void* fn_27_364DF8(void* self, int flags)
{
    if (self != 0 && (short)flags > 0) {
        __dl__FPv(self);
    }
    return self;
}
