#pragma force_active on
// The process object references the module's existing virtual table.
extern "C" unsigned char lbl_101_data_88F0[];

extern "C" void* fn_101_113D4(void* object) {
    *static_cast<void**>(object) = lbl_101_data_88F0;
    return object;
}
