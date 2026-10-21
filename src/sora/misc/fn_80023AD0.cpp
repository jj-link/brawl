#pragma force_active on
extern "C" {
void fn_80023AD0(void* r, short a, short b, int c, int d) {
    *(int*)((char*)r + 0x24) = c;
    *(int*)((char*)r + 0x28) = d;
    *(short*)((char*)r + 0x34) = a;
    *(short*)((char*)r + 0x36) = b;
}
}
