#include <revolution/GX.h>
#pragma force_active on

struct Video {
    GXRenderModeObj mode;
    u32 unk3C;
    u32 unk40;
    float scale;
    u32 unk48;
    u8 enabled : 1;
    u8 alternate : 1;
    u8 wide : 1;
    u8 unused : 5;
    u8 modeIndex;
    u8 pad[2];
    u32 format;
};

struct VideoSize {
    u16 width;
    float scale;
};

extern GXRenderModeObj* lbl_80423428[6][4];
extern VideoSize lbl_80423488[6][2];
extern "C" void fn_801F13EC(const GXRenderModeObj*, GXRenderModeObj*, u16, u16);
extern "C" void fn_801A10A0(const GXRenderModeObj*);
extern "C" void fn_801E8DC8(const GXRenderModeObj*);
extern "C" void fn_801E98B0();

extern "C" void fn_80038570(Video* self, u32 enabled)
{
    if (self->enabled != enabled) {
        self->enabled = enabled;
        u32 index;
        if (!self->alternate) {
            if (enabled) index = 1;
            else index = 0;
        } else {
            index = (enabled != 0) + 2;
        }
        GXRenderModeObj* mode = lbl_80423428[self->modeIndex][(u16)index];
        fn_801F13EC(mode, &self->mode, 0, 0);
        u16 wide = 0;
        if (self->wide) wide = 1;
        u16 width = lbl_80423488[self->format][wide].width;
        self->scale = lbl_80423488[self->format][wide].scale;
        self->mode.viWidth = width;
        self->mode.viXOrigin = (720 - width) / 2;
        fn_801A10A0(mode);
        fn_801E8DC8(&self->mode);
        fn_801E98B0();
    }
}
