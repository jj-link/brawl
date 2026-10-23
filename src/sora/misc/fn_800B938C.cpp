#pragma force_active on
typedef unsigned int u32;

struct WindowSetting {
    u32 visible : 1;
    u32 low : 31;
    unsigned char pad[0x44];
};

extern "C" void setWindowRectVisible__5MuMsgFUlb(void* self, unsigned long index, bool visible) {
    WindowSetting* arr = *(WindowSetting**)((char*)self + 0xC);
    arr[index].visible = visible;
}
