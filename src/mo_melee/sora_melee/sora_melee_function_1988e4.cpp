#pragma force_active on
extern "C" void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
extern "C" void fn_27_1374C(void*, int);
extern "C" void __dl__FPv(void*);

class fn_27_Obj {
public:
    char unk0[0xC];
};

extern "C" {
fn_27_Obj* fn_27_1988E4(fn_27_Obj* self, int deleteFlag) {
    if (self) {
        __destroy_arr((char*)self + 0xC, fn_27_1374C, 0x48, 3);
        if (deleteFlag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
}
