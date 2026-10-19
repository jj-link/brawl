#pragma force_active on
extern "C" {
void fn_27_19841C(void* self, short flag);
void __dl__FPv(void* p);
}

extern "C" void* fn_126_4B7C(void* self, short flag) {
    if (self != 0) {
        fn_27_19841C(self, -1);
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
