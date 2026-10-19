#pragma force_active on
extern "C" void fn_8015C238(void*, int);
extern "C" void __dl__FPv(void*);

extern "C" {
void* fn_79_198(void* self, int flags) {
    if (self) {
        fn_8015C238(self, 0);
        if (flags > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
}
