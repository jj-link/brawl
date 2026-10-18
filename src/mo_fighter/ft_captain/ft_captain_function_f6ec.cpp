#pragma force_active on
extern "C" {

extern void* lbl_100_data_67FC;

void fn_100_F6EC(void* out) {
    *static_cast<void**>(out) = &lbl_100_data_67FC;
}

}
