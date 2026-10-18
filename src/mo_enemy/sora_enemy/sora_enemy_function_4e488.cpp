#pragma force_active on
extern "C" void fn_41_3056C(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_41_4E488(void* self, short destroy) {
    if (self != 0) {
        fn_41_3056C(static_cast<char*>(self) + 4, -1);
        if (destroy > 0)
            __dl__FPv(self);
    }
    return self;
}
