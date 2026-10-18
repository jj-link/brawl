#pragma force_active on
struct CaptainHolder {
    char pad[0x1c];
    unsigned int* m_flags;
};

extern "C" void fn_100_98AC(CaptainHolder* self, unsigned int bits, int index) {
    unsigned int* arr = self->m_flags;
    arr[index] |= bits;
}
