#pragma force_active on
extern "C" {
    void* fn_27_31270(void*, short);
    void* fn_27_25740(void*, short);
    void __dl__FPv(void*);

    void* fn_41_2B4BC(void* self, short arg2) {
        if (self != 0) {
            fn_27_31270(static_cast<unsigned char*>(self) + 0x5c, -1);
            fn_27_25740(self, 0);
            if (arg2 > 0) {
                __dl__FPv(self);
            }
        }
        return self;
    }
}
