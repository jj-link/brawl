#pragma force_active on
extern "C" void fn_41_51B5C(void*, short);
extern "C" void fn_41_51A5C(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_41_51BBC(void* self, int shouldDelete) {
    if (self != 0) {
        fn_41_51B5C(static_cast<char*>(self) + 0xC8, -1);
        fn_41_51A5C(static_cast<char*>(self) + 4, -1);
        if (static_cast<short>(shouldDelete) > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
