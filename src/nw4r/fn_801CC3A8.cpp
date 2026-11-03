#pragma force_active on
extern "C" void fn_8015C238(void*, int);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_801CC3A8(void* self, int flags) {
    if (self != 0) {
        void* a = (char*)self + 0x384;
        if (a != 0) {
            fn_8015C238(a, 0);
        }
        void* b = (char*)self + 0x378;
        if (b != 0) {
            fn_8015C238(b, 0);
        }
        if (flags > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
