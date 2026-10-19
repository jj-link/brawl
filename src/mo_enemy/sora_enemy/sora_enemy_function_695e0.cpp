#pragma force_active on
extern "C" void fn_41_69BF0(void*, short);
extern "C" void fn_41_69574(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_41_695E0(void* self, short count) {
    if (self) {
        fn_41_69BF0((char*)self + 0x128, -1);
        fn_41_69574((char*)self + 4, -1);
        if (count > 0)
            __dl__FPv(self);
    }
    return self;
}
