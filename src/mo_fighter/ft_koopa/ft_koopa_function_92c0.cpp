#pragma force_active on
extern "C" void fn_102_92C0(void* self, int value, unsigned int index) {
    int* arr = *(int**)((char*)self + 0xc);
    arr[index] = arr[index] - value;
}
