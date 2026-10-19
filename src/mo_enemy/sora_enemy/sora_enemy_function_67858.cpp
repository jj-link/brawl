#pragma force_active on
extern "C" void fn_41_67958(void*, short);
extern "C" void fn_41_677EC(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_41_67858(void* self, short flag) {
    if (self != 0) {
        fn_41_67958((char*)self + 0xC8, -1);
        fn_41_677EC((char*)self + 4, -1);
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
