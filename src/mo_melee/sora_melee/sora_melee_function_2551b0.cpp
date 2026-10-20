#pragma force_active on

struct Fn27Obj {
    char pad0[0x48];
    unsigned char b48;
    unsigned char b49;
    unsigned char b4a;
};

extern "C" {
extern unsigned int lbl_27_bss_59C0;

void fn_27_254CDC(int);
void* getInstance__8ipSwitchFv();
void fn_8004A914(void*, int);

int fn_27_2551B0(Fn27Obj* self) {
    if (self->b49 != 0 && lbl_27_bss_59C0 != 0) {
        if (self->b4a == 0) {
            return 0;
        }
        fn_27_254CDC(0);
        self->b48 = 0;
        self->b49 = 0;
    }
    fn_8004A914(getInstance__8ipSwitchFv(), 0);
    return 1;
}
}
