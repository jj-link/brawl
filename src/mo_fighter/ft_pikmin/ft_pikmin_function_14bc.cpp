#pragma force_active on
extern "C" void* fn_27_1A5CCC(void* ptr, short size);

extern "C" void* fn_113_14BC(void* self, short flag) {
    if (self != 0) {
        fn_27_1A5CCC(self, (short)-1);
        if (flag > 0) {
            operator delete(self);
        }
    }
    return self;
}
