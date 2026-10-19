#pragma force_active on
extern "C" void fn_41_37B18(void*, short);
extern "C" void fn_41_37944(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_41_379B0(void* self, short shouldDelete) {
    if (self != 0) {
        fn_41_37B18((char*)self + 0x68, -1);
        fn_41_37944((char*)self + 4, -1);
        if (shouldDelete > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
