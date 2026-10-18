#pragma force_active on
extern "C" void fn_41_2D244(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_41_42600(void* self, int flag) {
    if (self != 0) {
        fn_41_2D244(static_cast<char*>(self) + 4, -1);
        if (static_cast<short>(flag) > 0)
            __dl__FPv(self);
    }
    return self;
}
