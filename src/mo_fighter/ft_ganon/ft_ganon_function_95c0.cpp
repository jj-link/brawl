#pragma force_active on
struct Result {
    unsigned int a;
    unsigned int b;
    unsigned int c;
};

extern "C" Result fn_109_9494(void* a, void* b);

extern "C" const Result& fn_109_95C0(void* a, void* b) {
    return fn_109_9494(a, b);
}
