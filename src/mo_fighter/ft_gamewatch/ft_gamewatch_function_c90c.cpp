#pragma force_active on
extern "C" void fn_107_C7E0(void* result, void* arg1, void* arg2);

extern "C" void* fn_107_C90C(void* arg1, void* arg2) {
    unsigned char result[12];
    fn_107_C7E0(result, arg1, arg2);
    return result;
}
