#pragma force_active on
extern "C" void fn_27_19C818(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_97_7C5C(void* self, int doDelete) {
    if (self != 0) {
        fn_27_19C818(static_cast<char*>(self), -1);
        if (static_cast<short>(doDelete) > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
