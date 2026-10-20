#include <types.h>
#pragma force_active on

extern "C" void EnableScnMdlCallbackTiming__Q34nw4r3g3d12ScnMdlSimpleFUl(void* model, u32 flag);

struct D30 {
    u32 w[12];
};

struct CbData {
    u32 unk0;
    u8 pad[0x4C];
    D30 data;
};

struct Sub {
    u32 unk0;
    CbData* cb;
    u32 unk8;
    u32 unkC;
};

struct Mdl {
    u8 pad[0x11C];
    void* cbLink;
    u8 pad2[0x122 - 0x120];
    u16 unk122;
};

struct Self {
    u8 _0[0x44];
    void** handle;
    u8 _48[0xC4 - 0x48];
    u32 valC4;
    u8 _C8[0xD0 - 0xC8];
    Sub sub;
    u8 _E0[0x158 - 0xE0];
    D30* src;
};

extern "C" void fn_51_133FC(Self* self) {
    Sub* sub = &self->sub;
    if (sub != NULL) {
        Mdl* mdl = *(Mdl**)self->handle;
        if (mdl != NULL) {
            if (mdl->cbLink == NULL) {
                sub->unkC = 0;
                sub->cb->unk0 = self->valC4;
                mdl->cbLink = sub;
                EnableScnMdlCallbackTiming__Q34nw4r3g3d12ScnMdlSimpleFUl(mdl, 1);
                mdl->unk122 = (u16)sub->cb->unk0;
            }
            D30* src = self->src;
            if (src != NULL) {
                sub->cb->data = *src;
            }
        }
    }
}
