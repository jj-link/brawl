#pragma force_active on
extern "C" void fn_98_A150(char* obj, int mul, unsigned index) {
    int* arr = *(int**)(obj + 0xc);
    arr[index] *= mul;
}
