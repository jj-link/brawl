#pragma force_active on
extern "C" {
void* fn_27_5CC1C(void*, short);
void* fn_27_D3080(void*, short);
void __dl__FPv(void*);

void* fn_41_2F6CC(void* self, short memberDeleting) {
    if (self) {
        fn_27_5CC1C((char*)self + 0xAC, -1);
        if (self) {
            fn_27_D3080(self, -1);
        }
        if (memberDeleting > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
}
