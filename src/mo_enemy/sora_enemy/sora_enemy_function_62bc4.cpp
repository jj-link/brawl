#pragma force_active on
extern "C" void fn_41_62CC4(void*, short);
extern "C" void fn_41_62B58(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_41_62BC4(void* self, int param) {
    if (self) {
        fn_41_62CC4((char*)self + 0x368, -1);
        fn_41_62B58((char*)self + 4, -1);
        if ((short)param > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
