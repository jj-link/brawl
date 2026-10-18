#pragma force_active on

extern "C" const char lbl_101_data_C2F8[];

extern "C" void fn_101_24B18(void* ptr) {
    *reinterpret_cast<const char**>(ptr) = lbl_101_data_C2F8;
}
