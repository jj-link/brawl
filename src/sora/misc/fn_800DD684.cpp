#pragma force_active on
extern char lbl_8045A000[];
extern "C" void fn_800DE290(char*);
extern "C" void __dl__FPv(void*);
extern "C" void* fn_800DD684(void* self, int deleteFlag) {
    if (self != 0) {
        *(char**)((char*)self + 0x1E0) = lbl_8045A000;
        fn_800DE290((char*)self);
        if (deleteFlag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}