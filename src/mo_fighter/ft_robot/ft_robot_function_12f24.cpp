#pragma force_active on
extern "C" {
void* fn_27_5C674(void*, short);
void __dl__FPv(void*);

void* fn_120_12F24(void* self, short flag) {
    if (self != 0) {
        fn_27_5C674(self, -1);
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
}
