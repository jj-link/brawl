#pragma force_active on
extern "C" {
extern unsigned char lbl_2_data_2AF8[];

void fn_800B8A0C(void*, int);
void fn_2_37C(void*, int);
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void __dl__FPv(void*);

void* fn_2_21AF8(void* self, int flag) {
    if (self) {
        char* object = (char*)self;
        *(void**)(object + 0x668) = lbl_2_data_2AF8;
        fn_800B8A0C(*(void**)(object + 0x66C), 1);

        if (self) {
            __destroy_arr(object + 0x48, fn_2_37C, 0xA8, 9);
        }

        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
}
