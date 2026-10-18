#pragma force_active on
extern "C" {
extern const char lbl_98_data_3044[];

void fn_98_7374(void* object, unsigned char value) {
    *static_cast<const void**>(object) = lbl_98_data_3044;
    static_cast<unsigned char*>(object)[4] = value;
}
}
