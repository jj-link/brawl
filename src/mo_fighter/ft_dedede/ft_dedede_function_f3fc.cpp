#pragma force_active on
extern "C" {
extern unsigned char lbl_117_data_8690[0x40];

void fn_117_F3FC(void* dest) {
    *reinterpret_cast<void**>(dest) = lbl_117_data_8690;
}
}
