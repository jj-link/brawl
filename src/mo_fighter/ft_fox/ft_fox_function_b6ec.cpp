#pragma force_active on
extern "C" void fn_97_B5C0(void*, void*, void*);

extern "C" void* fn_97_B6EC(void* arg0, void* arg1) {
    struct Result {
        unsigned char bytes[16];
    } result;

    fn_97_B5C0(&result, arg0, arg1);
    return &result;
}
