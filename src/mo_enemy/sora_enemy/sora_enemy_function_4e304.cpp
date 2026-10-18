#pragma force_active on
extern "C" void fn_41_2D244(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_41_4E304(void* self, short shouldDelete) {
    if (self != 0) {
        fn_41_2D244(static_cast<char*>(self) + 4, -1);
        if (shouldDelete > 0)
            __dl__FPv(self);
    }
    return self;
}
