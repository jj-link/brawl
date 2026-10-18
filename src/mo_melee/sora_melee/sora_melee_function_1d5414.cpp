#pragma force_active on
extern "C" void fn_27_1D5414(char* self, int v, unsigned int i, unsigned int j) {
    int* arr = *(int**)(self + i * 4 + 0x58);
    arr[j] += v;
}
