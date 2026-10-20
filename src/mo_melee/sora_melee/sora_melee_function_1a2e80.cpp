#pragma force_active on
struct FnBits {
    unsigned int a : 5;
    unsigned int b : 5;
    unsigned int c : 22;
};

extern "C" void fn_27_1A2E80(char* p, unsigned int v) {
    ((FnBits*)(p + 8))->b = v;
}
