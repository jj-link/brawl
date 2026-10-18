#pragma force_active on
extern "C" void fn_41_C2BC(void* self, int val, unsigned int idx) {
    int* arr = *(int**)((char*)self + 0xc);
    arr[idx] += val;
}
