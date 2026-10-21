#pragma force_active on
typedef unsigned int u32;

struct WindowSetting {
    struct {
        u32 hi : 6;
        u32 bit25 : 1;
        u32 low : 25;
    } flags;
    unsigned char pad[0x44];
};

extern "C" void FUN_800b9448__5MuMsgFUlb(void* msg, u32 index, bool flag) {
    WindowSetting* arr = *reinterpret_cast<WindowSetting**>((char*)msg + 0xC);
    arr[index].flags.bit25 = flag;
}
