#pragma force_active on
extern "C" void fn_122_F98C(void* out, void* arg, void* value);

extern "C" void* fn_122_FAB8(void* arg, void* value) {
    unsigned char result[16];
    fn_122_F98C(result, arg, value);
    return result;
}
