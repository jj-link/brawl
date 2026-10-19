#pragma force_active on
extern "C" void fn_41_69BF0(void*, short);
extern "C" void fn_41_69940(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_41_699AC(void* self, short param) {
    if (self != 0) {
        fn_41_69BF0((char*)self + 0x2d8, -1);
        fn_41_69940((char*)self + 4, -1);
        if (param > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
