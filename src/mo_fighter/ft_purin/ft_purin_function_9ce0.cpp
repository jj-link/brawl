#pragma force_active on
extern "C" void* fn_124_9C80(void* object, short flag);
extern "C" void fn_124_9B4C(void* object, short flag);
extern "C" void __dl__FPv(void* p);

extern "C" void* fn_124_9CE0(void* self, short flag) {
    if (self != 0) {
        fn_124_9C80((char*)self + 0x134, -1);
        if (self != 0) {
            fn_124_9B4C(self, 0);
        }
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
