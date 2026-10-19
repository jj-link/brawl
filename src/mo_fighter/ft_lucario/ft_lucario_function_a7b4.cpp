#pragma force_active on
extern "C" void fn_118_A688(void*, void*, void*);

struct Result {
    unsigned char data[24];
};

extern "C" Result* fn_118_A7B4(void* a, void* b) {
    Result result;
    fn_118_A688(&result, a, b);
    return &result;
}
