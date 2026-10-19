#pragma force_active on
extern "C" void fn_41_35BE4(void*, short);
extern "C" void fn_41_35AF0(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_41_35C44(void* self, short flags) {
    if (self) {
        fn_41_35BE4(static_cast<char*>(self) + 0x2384, -1);
        fn_41_35AF0(static_cast<char*>(self) + 4, -1);
        if (flags > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
