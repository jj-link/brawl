#pragma force_active on
extern "C" {
void fn_91_A8E8(unsigned char* object, int value, unsigned int index) {
    int* table = *(int**)(object + 0xc);
    table[index] += value;
}
}
