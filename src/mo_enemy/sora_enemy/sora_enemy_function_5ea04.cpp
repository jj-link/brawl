#pragma force_active on
extern "C" void fn_41_5EE64(void* self, short shouldDelete);
extern "C" void fn_41_5E998(void* self, short shouldDelete);
extern "C" void __dl__FPv(void* p);

extern "C" void* fn_41_5EA04(void* self, short shouldDelete) {
    if (self != 0) {
        fn_41_5EE64((char*)self + 0xC8, -1);
        fn_41_5E998((char*)self + 4, -1);
        if (shouldDelete > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
