#pragma force_active on
extern "C" {
extern unsigned char lbl_100_data_64F8[];

extern "C" void fn_100_DDA0(void* arg) {
    *static_cast<void**>(arg) = lbl_100_data_64F8;
}
}
