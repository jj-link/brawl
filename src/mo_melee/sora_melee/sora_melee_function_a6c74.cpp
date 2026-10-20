#pragma force_active on
struct fn_27_A6C74_Inner {
    char _0[0x3c];
    int _3c;
};

extern "C" void fn_27_A6C74(void* a, int b) {
    fn_27_A6C74_Inner* inner = *(fn_27_A6C74_Inner**)((char*)a + 4);
    inner->_3c = b;
}
