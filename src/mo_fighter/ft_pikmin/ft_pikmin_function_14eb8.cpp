#pragma force_active on
extern "C" void* fn_27_1A4A84(void* ptr, short count);
void operator delete(void* p);

extern "C" void* fn_113_14EB8(void* self, short flag) {
    if (self != 0) {
        fn_27_1A4A84(self, -1);
        if (flag > 0) {
            operator delete(self);
        }
    }
    return self;
}
