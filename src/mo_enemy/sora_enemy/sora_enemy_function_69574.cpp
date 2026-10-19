#pragma force_active on
extern "C" void fn_41_69BF0(void*, short);
extern "C" void fn_41_69508(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_41_69574(void* self, short count) {
    if (self != 0) {
        fn_41_69BF0((char*)self + 0xF8, -1);
        fn_41_69508((char*)self + 4, -1);
        if (count > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
