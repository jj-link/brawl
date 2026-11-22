#include <types.h>
#include <nw4r/g3d/g3d_resmdl.h>
#pragma force_active on
extern "C" {
extern int lbl_80455D70[4];
extern const f32 lbl_805A2200;
void fn_800B2F84(void*, const char*, void*, int, u32*, int);
void fn_800B3190(void*, void*, void*, int, int);
}
struct MuObject {
    u32 flags, unk4, unk8, unkC, unk10, unk14, unk18, unk1C, unk20, unk24;
    int unk28, unk2C, unk30, unk34;
    u8 unk38;
    f32 unk3C, unk40, unk44, unk48, unk4C, unk50;
    int heap, unk58;
    void* vtable;
};
inline void clearRange(char* p, char* end) {
    do {
        *(int*)p = 0;
        p += 4;
    } while (p < end);
}
extern "C" MuObject* fn_800B2BEC(MuObject* self, const char* name, void* arg2, int arg3, void* src, u32* arg5, int heap) {
    self->vtable = lbl_80455D70;
    self->flags |= 0x80000000;
    self->unk4 = 0;
    self->unk8 = 0;
    self->unkC = 0;
    self->unk10 = 0;
    self->unk14 = 0;
    self->unk18 = 0;
    self->unk1C = 0;
    self->unk20 = 0;
    clearRange((char*)&self->unk24, (char*)&self->unk34);
    self->unk34 = -1;
    self->unk38 = 0xff;
    self->unk58 = 0;
    self->heap = heap;
    if (src == 0) {
        fn_800B2F84(self, name, arg2, arg3, arg5, heap);
    } else {
        fn_800B3190(self, src, arg2, arg3, heap);
    }
    self->unk44 = lbl_805A2200;
    self->unk40 = lbl_805A2200;
    self->unk3C = lbl_805A2200;
    self->unk50 = lbl_805A2200;
    self->unk4C = lbl_805A2200;
    self->unk48 = lbl_805A2200;
    char* node = (char*)((nw4r::g3d::ResMdl*)&self->unk8)->GetResNode(0).ptr();
    for (;;) {
        int off = *(int*)(node + 0x5c);
        char* next;
        if (off == 0) {
            next = 0;
        } else {
            next = node + off;
        }
        if (next == 0) {
            break;
        }
        node = next;
    }
    self->unk34 = node ? *(int*)(node + 0xc) : 0;
    return self;
}
