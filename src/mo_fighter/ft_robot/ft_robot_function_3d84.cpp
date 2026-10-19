#pragma force_active on
extern "C" void* fn_27_1A3738(void* ptr, short shouldDelete);

extern "C" void* fn_120_3D84(void* self, short flag) {
    if (self != 0) {
        fn_27_1A3738(self, -1);
        if (flag > 0) {
            operator delete(self);
        }
    }
    return self;
}
