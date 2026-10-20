#pragma force_active on
extern "C" {
void __dt__24soCollisionHitModuleImplFv(void*, short);
void fn_27_CC984(void*, short);
void fn_27_4CAA0(void*, short);
void fn_27_CC654(void*, short);
void __dl__FPv(void*);
}

extern "C" void* fn_41_2F5D0(void* self, short deleteFlag) {
    if (self != 0) {
        short destroy = -1;
        __dt__24soCollisionHitModuleImplFv(static_cast<char*>(self) + 0x1A4, destroy);
        fn_27_CC984(static_cast<char*>(self) + 0x160, destroy);
        fn_27_4CAA0(static_cast<char*>(self) + 0xDC, destroy);
        fn_27_CC654(self, destroy);
        if (deleteFlag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
