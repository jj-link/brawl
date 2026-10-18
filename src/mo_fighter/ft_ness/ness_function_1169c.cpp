#pragma force_active on
// Callback object constructor: store the address of the module's 0x40-byte data
// block (used as the object's virtual table) into the object's first word.
extern "C" unsigned char lbl_101_data_8A40[];

extern "C" void fn_101_1169C(void* object) {
    *static_cast<void**>(object) = lbl_101_data_8A40;
}
