#pragma force_active on
extern "C" void fn_97_B410(void* self, int index) {
    int* arr = *(int**)((char*)self + 0xc);
    arr[index]++;
}
