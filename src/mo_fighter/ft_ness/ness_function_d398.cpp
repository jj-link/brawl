#pragma force_active on
extern "C" void fn_101_D398(char* self, int index) {
    int* table = *(int**)(self + 0x1c);
    table[index] = 0;
}
