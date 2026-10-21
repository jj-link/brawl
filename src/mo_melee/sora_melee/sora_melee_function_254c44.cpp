#pragma force_active on

extern "C" {
extern unsigned int lbl_27_bss_59C0;
extern char g_Network[];
extern char lbl_27_data_52C28[];

void fn_27_254CDC(int);
void fn_27_254CE8(void (*)(void*));
void* fn_27_241EA4(void*, int);
void __dl__FPv(void*);

void* fn_27_254C44(void* self, int flag) {
    if (self) {
        *(void**)((char*)self + 0x3C) = lbl_27_data_52C28;
        lbl_27_bss_59C0 = 0;
        if (g_Network) {
            fn_27_254CDC(0);
            fn_27_254CE8(0);
        }
        if (self)
            fn_27_241EA4(self, 0);
        if (flag > 0)
            __dl__FPv(self);
    }
    return self;
}
}
