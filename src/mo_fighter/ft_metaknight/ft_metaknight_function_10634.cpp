#pragma force_active on
extern "C" void __dt__17soModelModuleImplFv(void*, short);
extern "C" void* fn_27_CBDE8(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_111_10634(void* self, short flag) {
    if (self != 0) {
        __dt__17soModelModuleImplFv(static_cast<unsigned char*>(self) + 0x114, -1);
        fn_27_CBDE8(self, -1);
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
