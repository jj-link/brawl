#pragma force_active on
extern "C" void fn_27_B156C(void* object, int index, void* value);

extern "C" void fn_27_604D0(void* object, void* value) {
    fn_27_B156C(static_cast<char*>(object) + 0x44, 1, value);
}
