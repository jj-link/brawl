#pragma force_active on
extern "C" void fn_99_8B80(unsigned char* self, int idx) {
    int* arr = *(int**)(self + 0xc);
    arr[idx]++;
}
