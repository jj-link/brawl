#pragma force_active on
extern "C" {
void fn_77_F54(void*, int);
void __dl__FPv(void*);

void* fn_77_10E8(void* self, int flags) {
    if (self != 0) {
        fn_77_F54(self, 0);
        if (flags > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
}
