#pragma force_active on
extern "C" {
void fn_27_19C818(void*, short);
void __dl__FPv(void*);

void* fn_106_4D98(void* self, short flag) {
    if (self != 0) {
        fn_27_19C818(self, -1);
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
}
