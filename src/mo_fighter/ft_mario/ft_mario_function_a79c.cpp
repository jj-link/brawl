#pragma force_active on
extern "C" {
void fn_91_A79C(void* object, int index) {
    int* table = *reinterpret_cast<int**>(static_cast<unsigned char*>(object) + 0x1c);
    table[index] = 0;
}
}
