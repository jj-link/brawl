#pragma force_active on
extern "C" {
void* fn_27_14B698(void*, short);
void __dl__FPv(void*);

void* fn_106_516C(void* self, short flag) {
    if (self != 0) {
        fn_27_14B698(self, -1);
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
}
