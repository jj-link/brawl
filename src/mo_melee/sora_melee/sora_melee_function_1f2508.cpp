#pragma force_active on
extern "C" void fn_27_1F13E4(void*, int, int);

extern "C" void fn_27_1F2508(void* arg0, void* arg1, void* arg2) {
    fn_27_1F13E4(arg2, 0, 1);
    *reinterpret_cast<unsigned char*>(static_cast<char*>(arg0) + 0x385) = 0xF0;
}
