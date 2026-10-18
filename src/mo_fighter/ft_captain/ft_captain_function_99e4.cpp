#pragma force_active on
extern "C" void fn_100_99E4(char* self, int value, int index) {
    int* arr = *(int**)(self + 0xC);
    arr[index] += value;
}
