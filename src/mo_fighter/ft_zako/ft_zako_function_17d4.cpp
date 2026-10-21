#pragma force_active on
extern "C" void* fn_126_186C(void* ptr, short value);
extern "C" void* fn_126_1C4C(void* ptr, short value);
extern "C" void* fn_126_1CE8(void* object, short deleting);
extern "C" void* fn_126_1E20(void* self, short deleting);
extern "C" void* fn_27_125E20(void* self, short deleting);
extern "C" void __dl__FPv(void* p);

extern "C" void* fn_126_17D4(void* self, short deleting) {
    if (self != 0) {
        fn_126_186C((char*)self + 0x8084, -1);
        fn_126_1C4C((char*)self + 0x7bcc, -1);
        fn_126_1CE8((char*)self + 0x7b90, -1);
        fn_126_1E20((char*)self + 0x194, -1);
        fn_27_125E20(self, 0);
        if (deleting > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
