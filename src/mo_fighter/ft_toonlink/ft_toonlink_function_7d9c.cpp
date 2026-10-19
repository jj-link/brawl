#pragma force_active on
typedef short s16;

extern "C" {
void fn_121_7D2C(void* self, s16 arg);
void __dl__FPv(void* p);
}

extern "C" void* fn_121_7D9C(void* self, s16 flag) {
    if (self != 0) {
        fn_121_7D2C(self, -1);
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
