#pragma force_active on
extern "C" void* fn_41_426C0(void* self, short flag) {
    extern void fn_41_42660(void*, short);
    extern void __dl__FPv(void*);
    if (self != 0) {
        fn_41_42660((char*)self + 4, -1);
        if (flag > 0)
            __dl__FPv(self);
    }
    return self;
}
