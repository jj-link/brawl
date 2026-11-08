#pragma force_active on
extern "C" void fn_801CF9D4(void*, int);
extern "C" void fn_801C3040(void*, int);
extern "C" void __dl__FPv(void*);
extern "C" void* fn_801C46C4(void* self, int flag) {
    if (self) {
        void* sub = (char*)self + 0x410;
        if (sub) {
            fn_801CF9D4(sub, 0);
        }
        fn_801C3040((char*)self + 0xd8, -1);
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}