#pragma force_active on
extern "C" void fn_122_F814(void* self, unsigned int value, unsigned int index) {
    unsigned int* arr = *(unsigned int**)((char*)self + 0xc);
    arr[index] *= value;
}
