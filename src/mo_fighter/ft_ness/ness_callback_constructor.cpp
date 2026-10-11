// The callback object references the module's existing virtual table.
extern "C" unsigned char lbl_101_data_8988[];

extern "C" void* fn_101_1150C(void* object) {
    *static_cast<void**>(object) = lbl_101_data_8988;
    return object;
}
