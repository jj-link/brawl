#pragma force_active on
extern "C" {
extern char lbl_804659D0[0x18];

void fn_8018BCF0(void* output) {
    *static_cast<void**>(output) = lbl_804659D0;
}
}
