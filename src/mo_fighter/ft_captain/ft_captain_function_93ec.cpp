#pragma force_active on
extern "C" {
void* fn_27_C74E8(void*, short);
void* fn_100_191C(void* object, short deleting);
void __dl__FPv(void*);
}

extern "C" void* fn_100_93EC(void* self, short deleting) {
    if (self != 0) {
        fn_27_C74E8(reinterpret_cast<char*>(self) + 0xC5B4, static_cast<short>(-1));
        fn_100_191C(self, static_cast<short>(0));
        if (deleting > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
