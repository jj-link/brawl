#pragma force_active on
extern "C" void fn_118_A540(char* self, int delta, unsigned int index) {
    int* arr = *(int**)(self + 0xc);
    arr[index] += delta;
}
