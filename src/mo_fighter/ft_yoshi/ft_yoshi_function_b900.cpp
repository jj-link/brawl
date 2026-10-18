#pragma force_active on
typedef unsigned int u32;

extern "C" void fn_95_B900(char* self, u32 index) {
    int* arr = *(int**)(self + 0xc);
    arr[index]--;
}
