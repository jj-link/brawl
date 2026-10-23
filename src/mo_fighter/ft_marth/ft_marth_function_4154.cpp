#pragma force_active on

extern "C" void* fn_106_1EE4(void*, short);
extern "C" void* fn_106_1F40(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_106_4154(void* self, short flag) {
    if (self != 0) {
        fn_106_1EE4((char*)self + 0x14, 0);
        fn_106_1F40((char*)self + 8, 0);
        if (flag > 0)
            __dl__FPv(self);
    }
    return self;
}
