#pragma force_active on
extern "C" void fn_27_1A68FC(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_115_2888(void* self, int shouldDelete) {
    if (self != 0) {
        fn_27_1A68FC(self, -1);
        if ((short)shouldDelete > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
