#pragma force_active on
extern "C" void fn_27_D3464(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_41_29E4(void* self, short flag) {
    if (self != 0) {
        fn_27_D3464(static_cast<char*>(self) + 4, -1);
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
