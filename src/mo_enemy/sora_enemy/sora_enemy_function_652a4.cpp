#pragma force_active on
extern "C" void* fn_41_65698(void* self, short shouldDelete);
extern "C" void* fn_41_65238(void* self, short shouldDelete);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_41_652A4(void* self, short arg1) {
    if (self) {
        fn_41_65698((char*)self + 0x218, -1);
        fn_41_65238((char*)self + 0x4, -1);
        if (arg1 > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
