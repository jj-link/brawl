#pragma force_active on
extern "C" void fn_27_1A6B04(void*, short);

extern "C" float* fn_122_2850(float* self, short param) {
    if (self != 0) {
        fn_27_1A6B04(self, -1);
        if (param > 0) {
            delete self;
        }
    }
    return self;
}
