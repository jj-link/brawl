#pragma force_active on
extern "C" void fn_110_9948(void* self, int index) {
    int* arr = *(int**)((char*)self + 0xc);
    arr[index]--;
}
