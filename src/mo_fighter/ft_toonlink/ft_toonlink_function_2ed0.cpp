#pragma force_active on
extern "C" void fn_27_19C818(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_121_2ED0(void* self, int flag) {
    if (self != 0) {
        fn_27_19C818(self, -1);
        if (static_cast<short>(flag) > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
