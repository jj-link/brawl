#pragma force_active on
extern "C" {
void __dl__FPv(void* p);
void __dt__14snd3DGeneratorFv(void* self, int flags);
void fn_52_363C(void* self, int flags);
extern char lbl_52_data_1638[];

void* fn_52_4DE0(void* self, int flags) {
    if (self != 0) {
        void* ptr = *(void**)((char*)self + 0x188);
        *(void**)((char*)self + 0x3c) = lbl_52_data_1638;
        if (ptr != 0) {
            __dl__FPv(ptr);
        }
        *(void**)((char*)self + 0x188) = 0;
        __dt__14snd3DGeneratorFv((char*)self + 0x18c, -1);
        fn_52_363C(self, 0);
        if (flags > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
}
