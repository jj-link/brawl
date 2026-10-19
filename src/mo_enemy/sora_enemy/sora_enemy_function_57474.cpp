#pragma force_active on
extern "C" void* fn_41_57418(void* obj, short flag);
extern "C" void* fn_41_33D4C(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_41_57474(void* self, short flag) {
    if (self != 0) {
        fn_41_57418(reinterpret_cast<char*>(self) + 0x8, -1);
        fn_41_33D4C(self, 0);
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
