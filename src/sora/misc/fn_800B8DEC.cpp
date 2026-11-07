#pragma force_active on
#include <types.h>

struct Message;
struct WindowSetting {
    u32 flags;
    float f04, f08, f0C, f10;
    char _14[0x48 - 0x14];
};

extern const float lbl_805A2228;

extern "C" int attachMsgBuf__7MessageFUlPQ34nw4r3g3d12ScnMdlSimplePCcUcif(
    Message*, u32, void*, const char*, u8, int, float);
extern "C" void initWindowSetting__5MuMsgFPQ25MuMsg13WindowSetting(void*, WindowSetting*);

extern "C" void fn_800B8DEC(void* self, u32 idx, void* arg2, const char* str,
    float a, float b, float c, float d, float fontSize)
{
    attachMsgBuf__7MessageFUlPQ34nw4r3g3d12ScnMdlSimplePCcUcif(
        *(Message**)((char*)self + 0x8), idx, *(void**)((char*)arg2 + 0x10), str, 1, 3, fontSize);
    WindowSetting* ws = *(WindowSetting**)((char*)self + 0xC) + idx;
    initWindowSetting__5MuMsgFPQ25MuMsg13WindowSetting(self, ws);
    float f = lbl_805A2228 / fontSize;
    ws->f04 = a * f;
    ws->f08 = b * f;
    ws->f0C = c * f;
    ws->f10 = d * f;
}
