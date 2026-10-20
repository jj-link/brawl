#pragma force_active on
extern "C" void fn_48_1D70(void* self, unsigned char a, unsigned long b, float c) {
    *(unsigned char*)((char*)self + 0x184) = a;
    *(unsigned long*)((char*)self + 0x188) = b;
    *(float*)((char*)self + 0x18c) = c;
}
