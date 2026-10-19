#pragma force_active on
extern "C" void* fn_27_1A5CCC(void* ptr, short size);
extern "C" void __dl__FPv(void* p);

extern "C" {
void* fn_121_8B08(void* self, short size) {
    if (self != 0) {
        fn_27_1A5CCC(self, (short)-1);
        if (size > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
}
