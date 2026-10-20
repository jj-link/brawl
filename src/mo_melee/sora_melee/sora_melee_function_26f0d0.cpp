#pragma force_active on
extern "C" void* fn_27_5CC1C(void*, short);
void operator delete(void*);

extern "C" void* fn_27_26F0D0(void* self, int flag) {
    if (self) {
        fn_27_5CC1C(self, 0);
        if (flag > 0) {
            operator delete(self);
        }
    }
    return self;
}
