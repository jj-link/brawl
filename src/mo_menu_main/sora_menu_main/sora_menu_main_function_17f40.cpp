#pragma force_active on
extern char lbl_2_data_22D8[];

extern "C" {
void fn_2_37C(void*, int);
void fn_800B8A0C(void*, int);
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void __dl__FPv(void*);

void* fn_2_17F40(char* self, int flag) {
    if (self) {
        void* p = *reinterpret_cast<void**>(self + 0x66c);
        *reinterpret_cast<void**>(self + 0x668) = lbl_2_data_22D8;
        if (p) {
            fn_800B8A0C(p, 1);
        }
        if (self) {
            __destroy_arr(self + 0x48, fn_2_37C, 0xA8, 9);
        }
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
}
