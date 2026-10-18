#pragma force_active on
extern "C" void fn_91_A8B8(void* self, int factor, int index) {
    int* table = *(int**)((unsigned char*)self + 0xc);
    table[index] = table[index] * factor;
}
