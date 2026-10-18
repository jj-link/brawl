#pragma force_active on

extern "C" {
extern char lbl_96_data_BCA8[];
void fn_96_1D734(void*);
void fn_96_1DE6C(void*);
void fn_96_1DEE4(void*, short);
void fn_27_C3448(void*, short);
void __destroy_arr(void*, void (*)(void*), unsigned long, unsigned long);
}

extern "C" void* fn_96_1C44C(void* self, short deleting) {
    if (self != 0) {
        char* storage = static_cast<char*>(self);
        *(void**)storage = lbl_96_data_BCA8;
        *(void**)(storage + 4) = lbl_96_data_BCA8 + 12;
        fn_96_1D734(self);
        __destroy_arr(storage + 0x6c, fn_96_1DE6C, 0x18c, 7);
        fn_96_1DEE4(storage + 0x28, -1);
        fn_27_C3448(storage + 0xc, -1);
        if (deleting > 0) {
            operator delete(self);
        }
    }
    return self;
}
