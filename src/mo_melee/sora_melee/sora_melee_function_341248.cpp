#pragma force_active on
extern "C" {
int fn_27_341248(char* obj, int unused, int a, int b) {
    int idx = a - *(int*)(obj + 0x14);
    int* arr = *(int**)((char*)(obj + idx * 4) + 0x24);
    return arr[b];
}
}
