#pragma force_active on
extern "C" {
void fn_62_2CE8(void* self, int flags);
void __dl__FPv(void* p);
}

extern "C" void* fn_62_CEE0(void* self, int flags) {
    if (self != 0) {
        fn_62_2CE8(self, 0);
        if (flags > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
