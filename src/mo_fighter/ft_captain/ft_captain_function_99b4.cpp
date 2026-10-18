#pragma force_active on
extern "C" void fn_100_99B4(void* obj, int value, int index) {
    int* arr = *(int**)((char*)obj + 0xc);
    arr[index] *= value;
}
