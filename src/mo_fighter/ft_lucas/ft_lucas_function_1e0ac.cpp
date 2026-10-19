#pragma force_active on
extern "C" void* __dt__17soModelModuleImplFv(void*, short);
extern "C" void fn_27_19A5BC(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_114_1E0AC(void* self, short deleteFlag) {
    if (self != 0) {
        __dt__17soModelModuleImplFv(static_cast<unsigned char*>(self) + 0x78, -1);
        fn_27_19A5BC(self, -1);
        if (deleteFlag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
