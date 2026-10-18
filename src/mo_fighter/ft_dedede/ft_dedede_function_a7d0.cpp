#pragma force_active on
extern "C" void fn_117_A7D0(void* self, int index) {
    int* counts = *(int**)((char*)self + 0xc);
    counts[index]--;
}
