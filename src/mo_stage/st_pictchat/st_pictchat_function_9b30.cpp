#pragma force_active on
typedef unsigned int u32;

extern "C" void fn_73_9B30(void* this_, u32 a, u32 b) {
    *(u32*)((char*)this_ + 0x5b0) = a;
    *(u32*)((char*)this_ + 0x5b8) = b;
}
