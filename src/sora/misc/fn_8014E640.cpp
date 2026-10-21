#pragma force_active on
extern "C" {
void* memset(void* s, int c, unsigned long n);

void fn_8014E640(void* self) {
    memset((char*)self + 0x30, 0, 0x40);
    *(short*)((char*)self + 0x70) = 0;
}
}
