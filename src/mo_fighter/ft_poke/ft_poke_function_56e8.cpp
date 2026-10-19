#pragma force_active on
extern "C" void* fn_27_1A3328(void*, short);
void operator delete(void* p);

extern "C" void* fn_116_56E8(void* self, short shouldDelete) {
    if (self != 0) {
        fn_27_1A3328(self, static_cast<short>(-1));
        if (shouldDelete > 0) {
            operator delete(self);
        }
    }
    return self;
}
