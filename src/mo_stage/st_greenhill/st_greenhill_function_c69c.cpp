#pragma force_active on
extern "C" {
void fn_72_1194(void* self, int flag);
void __dl__FPv(void* p);
}

extern "C" void* fn_72_C69C(void* self, int size)
{
    if (self != 0) {
        fn_72_1194(self, 0);
        if (size > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
