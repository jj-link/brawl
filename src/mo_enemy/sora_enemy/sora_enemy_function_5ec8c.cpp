#pragma force_active on
extern "C" void fn_41_5EE64(void*, short);
extern "C" void fn_41_5EC20(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_41_5EC8C(void* self, short del) {
    if (self != 0) {
        fn_41_5EE64(static_cast<char*>(self) + 0x1E8, -1);
        fn_41_5EC20(static_cast<char*>(self) + 4, -1);
        if (del > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
