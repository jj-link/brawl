#pragma force_active on
extern "C" void fn_92_9B20(char* self, int value, unsigned int index) {
    int* arr = *(int**)(self + 0xc);
    arr[index] *= value;
}
