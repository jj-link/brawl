#pragma force_active on
extern "C" {
void fn_27_614C4(void*, short);
void* fn_27_D3080(void*, short);
void __dl__FPv(void*);

void* fn_106_46C4(void* self, short memberDeleting) {
    if (self) {
        fn_27_614C4((char*)self + 0xAC, -1);
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
