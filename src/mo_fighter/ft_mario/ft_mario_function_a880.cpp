#pragma force_active on
extern "C" {
int fn_91_A880(void* self, int index) {
    int* table = *(int**)((unsigned char*)self + 0xc);
    int old = table[index];
    table[index] = old + 1;
    return old;
}
}
