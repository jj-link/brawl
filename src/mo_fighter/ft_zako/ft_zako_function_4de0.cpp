#pragma force_active on
extern "C" {
void* fn_27_CC7EC(void*, short);
void __dl__FPv(void*);

void* fn_126_4DE0(void* self, short deleteFlag) {
    if (self != 0) {
        fn_27_CC7EC(self, -1);
        if (deleteFlag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
}
