#pragma force_active on
extern "C" void* fn_27_1B055C(void* p, int idx) {
    int* ip = (int*)p;
    int n = (ip[2] >> 30) + idx;
    if (n >= 1) {
        n -= 1;
    }
    return (char*)p + n * 0x68 + 0xC;
}
