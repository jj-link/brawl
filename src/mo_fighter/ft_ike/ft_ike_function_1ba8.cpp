#pragma force_active on
extern "C" {
void fn_119_1B44(void*, short);
void __dl__FPv(void*);
}

extern "C" void* fn_119_1BA8(void* self, short flag) {
    if (self != 0) {
        fn_119_1B44(self, (short)0);
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
