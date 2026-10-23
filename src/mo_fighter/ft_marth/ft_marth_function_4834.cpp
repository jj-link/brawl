#pragma force_active on
extern "C" {
void* fn_27_48BE8(void*, short);
void* fn_27_4742C(void*, short);
void* fn_27_CB800(void*, short);
void* fn_27_19FB24(void*, short);
void* fn_27_19E398(void*, short);
void __dl__FPv(void*);
}

extern "C" void* fn_106_4834(void* self, short del) {
    if (self != 0) {
        short destroy = -1;
        fn_27_48BE8((char*)self + 0x354, destroy);
        fn_27_4742C((char*)self + 0x344, destroy);
        fn_27_CB800((char*)self + 0x248, destroy);
        fn_27_19FB24((char*)self + 0xCC, destroy);
        fn_27_19E398(self, destroy);
        if (del > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
