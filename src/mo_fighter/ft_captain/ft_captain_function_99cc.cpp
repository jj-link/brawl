#pragma force_active on
extern "C" void fn_100_99CC(char* self, int value, int index) {
    int* arr = *reinterpret_cast<int**>(self + 0xc);
    arr[index] -= value;
}
