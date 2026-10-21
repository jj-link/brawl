#pragma force_active on
struct Accesser { char prefix[8]; void* owner; };

extern "C" {
extern const char lbl_95_data_5F8[];
extern const char lbl_95_data_36D8[];
void* __dynamic_cast(void*, int, const void*, const void*, short);
void fn_27_16AC30(void*, void*);
void fn_95_AE3C(void*);

void fn_95_F610(void* a, void* b, int c) {
    fn_27_16AC30(a, b);
    if (c != 0x1a && c != 0x1b && c != 0x1d && c != 0x1f && c != 0x20) {
        void* owner = __dynamic_cast(((Accesser*)b)->owner, 0x3c, lbl_95_data_5F8, lbl_95_data_36D8, short(1));
        fn_95_AE3C(owner);
    }
}
}
