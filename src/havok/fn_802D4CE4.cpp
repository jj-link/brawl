#pragma force_active on
extern "C" {
extern unsigned char lbl_804873E8[];

void fn_802D4CE4(void* arg0) {
    if (arg0 != 0) {
        *static_cast<void**>(arg0) = lbl_804873E8;
    }
}
}
