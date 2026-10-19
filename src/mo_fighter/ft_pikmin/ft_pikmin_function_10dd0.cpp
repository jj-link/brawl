#pragma force_active on
extern "C" {
extern const char lbl_113_data_61C[];
extern const char lbl_113_data_2950[];
void* __dynamic_cast(void*, int, const void*, const void*, short);
void* fn_113_C3D4(void*);

void fn_113_10DD0(void* p) {
    void* r = __dynamic_cast(p, 0x3c, lbl_113_data_61C, lbl_113_data_2950, short(0));
    if (r != 0) {
        fn_113_C3D4(r);
    }
}
}
