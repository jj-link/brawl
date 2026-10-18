#pragma force_active on
extern "C" {

extern unsigned char lbl_100_data_6578[];

void fn_100_DF44(void* object) {
    *static_cast<unsigned int*>(object) = reinterpret_cast<unsigned int>(lbl_100_data_6578);
}

}
