#pragma force_active on
extern "C" {
extern unsigned char lbl_100_data_668C[0x40];
}

// Writes the address of the module's data block into the pointer passed in r3.
extern "C" void fn_100_F71C(void** ptr) {
    *ptr = static_cast<void*>(&lbl_100_data_668C[0]);
}
