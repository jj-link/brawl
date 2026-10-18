#pragma force_active on
extern "C" void fn_91_A8D0(unsigned char* obj, int value, int index) {
    int* arr = *(int**)(obj + 0xc);
    arr[index] -= value;
}
