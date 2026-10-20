#pragma force_active on
typedef short s16;

extern "C" {
void* fn_106_9248(void* object, s16 flag);
void fn_106_9114(void* object, s16 flag);
void __dl__FPv(void* p);
}

extern "C" void* fn_106_92A8(void* self, s16 flag) {
    if (self != 0) {
        s16 neg = -1;
        fn_106_9248((char*)self + 0x1c8, neg);
        if (self != 0) {
            s16 zero = 0;
            fn_106_9114(self, zero);
        }
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
