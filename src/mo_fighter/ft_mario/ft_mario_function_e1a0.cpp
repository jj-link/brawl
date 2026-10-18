#pragma force_active on
extern "C" {
extern unsigned char lbl_91_data_7710[];

void fn_91_E1A0(void* object) {
    *reinterpret_cast<void**>(object) = &lbl_91_data_7710[0];
}
}
