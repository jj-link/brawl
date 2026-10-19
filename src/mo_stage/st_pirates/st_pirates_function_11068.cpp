#pragma force_active on
extern "C" void fn_52_363C(void* self, int flag);

extern "C" void* fn_52_11068(void* self, int flag) {
    if (self != 0) {
        fn_52_363C(self, 0);
        if (flag > 0) {
            operator delete(self);
        }
    }
    return self;
}
