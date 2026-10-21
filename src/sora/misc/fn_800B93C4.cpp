#pragma force_active on
typedef unsigned int u32;
typedef unsigned char u8;

struct WindowSetting {
    u32 unused : 1;
    u32 align : 2;
    u32 pad : 29;
    char _4[0x44];
};

extern "C" void setAlignMode__5MuMsgFUlQ25MuMsg9AlignMode(void* self, u32 msgIndex, u32 alignMode) {
    u32* arr = *(u32**)((u8*)self + 0xc);
    WindowSetting* w = (WindowSetting*)arr + msgIndex;
    w->align = alignMode;
}
