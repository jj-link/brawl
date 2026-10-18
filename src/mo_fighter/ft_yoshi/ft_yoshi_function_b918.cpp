#pragma force_active on
extern "C" void fn_95_B918(void* self, unsigned int index) {
    int* counts = *(int**)((char*)self + 0xc);
    counts[index]++;
}
