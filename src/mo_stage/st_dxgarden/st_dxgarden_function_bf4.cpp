#pragma force_active on
extern "C" void fn_77_BF4(void* self, unsigned char a, int b, float c) {
    *(unsigned char*)((char*)self + 0x184) = a;
    *(int*)((char*)self + 0x188) = b;
    *(float*)((char*)self + 0x18c) = c;
}
