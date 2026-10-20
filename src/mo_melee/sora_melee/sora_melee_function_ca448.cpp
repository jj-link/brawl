#pragma force_active on
extern "C" {
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void fn_27_A6978(void*, int);
void __dl__FPv(void*);

struct fn_27_CA448_obj {
    char pad[0xc];
};

fn_27_CA448_obj* fn_27_CA448(fn_27_CA448_obj* self, int doDelete) {
    if (self) {
        __destroy_arr((char*)self + 0xc, fn_27_A6978, 0x24, 0xb);
        if (doDelete > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
}
