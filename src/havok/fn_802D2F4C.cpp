#pragma force_active on
typedef unsigned char u8;

extern "C" void fn_802D2F4C(int unused, void* arg1) {
    *(int*)arg1 = 0x12;
    *(u8*)((u8*)arg1 + 4) = 1;
}
