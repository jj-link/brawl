#pragma force_active on
extern "C" void fn_100_9964(char* self, int index) {
    int* table = *reinterpret_cast<int**>(self + 0xC);
    table[index] = table[index] - 1;
}
