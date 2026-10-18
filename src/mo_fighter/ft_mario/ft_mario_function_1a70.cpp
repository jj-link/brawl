#pragma force_active on
extern "C" {
extern unsigned char lbl_91_data_3490[];
void fn_91_1A70(void* object, unsigned char value) {
    *static_cast<void**>(object) = lbl_91_data_3490;
    static_cast<unsigned char*>(object)[4] = value;
}
}
