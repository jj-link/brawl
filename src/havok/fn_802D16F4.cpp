#pragma force_active on
typedef unsigned char u8;
typedef unsigned long u32;

extern "C" {
void fn_802D16F4(void* arg0, void* arg1) {
    *(u32*)((u8*)arg1 + 0x0) = *(u32*)((u8*)arg0 + 0x3C);
    *(u8*)((u8*)arg1 + 0x4) = 1;
}
}
