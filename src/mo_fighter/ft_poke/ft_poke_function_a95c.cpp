#pragma force_active on
extern "C" void fn_116_A95C(unsigned char* work, unsigned int value, unsigned int index) {
    unsigned int* arr = *(unsigned int**)(work + 0xc);
    arr[index] += value;
}
