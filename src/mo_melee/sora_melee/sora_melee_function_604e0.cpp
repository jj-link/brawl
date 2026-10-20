#pragma force_active on
extern "C" void fn_27_B156C(void* object, int index, void* value);

extern "C" void fn_27_604E0(void* object, void* value) {
    fn_27_B156C(static_cast<char*>(object) + 0x44, 0, value);
}
