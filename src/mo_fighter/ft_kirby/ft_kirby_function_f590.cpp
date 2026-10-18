#pragma force_active on
extern "C" void fn_96_F590(void* self, int value, unsigned int index) {
    int* arr = *(int**)((char*)self + 0xc);
    arr[index] -= value;
}
