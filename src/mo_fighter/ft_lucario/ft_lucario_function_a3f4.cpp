#pragma force_active on
extern "C" void fn_118_A3F4(void* self, unsigned int index) {
    int* table = *(int**)((char*)self + 0x1c);
    table[index] = 0;
}
