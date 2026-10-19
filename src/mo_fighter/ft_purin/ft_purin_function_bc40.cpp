#pragma force_active on
extern "C" {
extern unsigned char lbl_124_data_5BE8[0x40];

void fn_124_BC40(void* arg0) {
    *reinterpret_cast<void**>(arg0) = lbl_124_data_5BE8;
}
}
