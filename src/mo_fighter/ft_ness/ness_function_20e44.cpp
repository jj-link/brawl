#pragma force_active on
extern "C" unsigned char lbl_101_data_BB70[];

extern "C" void fn_101_20E44(void* object, void* other) {
    *reinterpret_cast<unsigned char**>(object) = lbl_101_data_BB70;
}