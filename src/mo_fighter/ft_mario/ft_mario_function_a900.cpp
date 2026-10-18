#pragma force_active on
extern "C" void fn_91_A900(int** obj, int value, int index) {
    int* arr = *reinterpret_cast<int**>(reinterpret_cast<char*>(obj) + 12);
    arr[index] = value;
}
