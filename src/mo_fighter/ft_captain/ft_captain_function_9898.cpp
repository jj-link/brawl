#pragma force_active on
extern "C" void fn_100_9898(void* self, int index) {
    int* table = *(int**)((char*)self + 0x1c);
    table[index] = 0;
}
