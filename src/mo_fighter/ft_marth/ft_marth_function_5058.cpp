#pragma force_active on
extern "C" {
void* fn_27_CC7EC(void*, short);
void __dl__FPv(void*);

void* fn_106_5058(void* self, short flag) {
    if (self != 0) {
        fn_27_CC7EC(self, -1);
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
}
