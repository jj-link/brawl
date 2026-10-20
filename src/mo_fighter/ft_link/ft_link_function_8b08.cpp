#pragma force_active on
extern "C" {
void* fn_27_1A5CCC(void* ptr, short size);
void __dl__FPv(void* ptr);

void* fn_93_8B08(void* self, short flag) {
    if (self != 0) {
        fn_27_1A5CCC(self, (short)-1);
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
}
