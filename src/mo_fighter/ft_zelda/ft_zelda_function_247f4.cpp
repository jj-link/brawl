#pragma force_active on
extern "C" unsigned char lbl_104_data_D200[];

extern "C" void fn_104_247F4(void* object) {
    *static_cast<void**>(object) = lbl_104_data_D200;
}
