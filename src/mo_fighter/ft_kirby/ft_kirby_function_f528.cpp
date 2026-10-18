#pragma force_active on
extern "C" void fn_96_F528(void* self, unsigned int index) {
    int* arr = *(int**)((char*)self + 0xc);
    arr[index] -= 1;
}
