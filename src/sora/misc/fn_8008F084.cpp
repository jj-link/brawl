#include <types.h>
#include <nw4r/g3d/g3d_resmdl.h>
#pragma force_active on

extern "C" {
extern void* lbl_8049DEC8[3];
extern u8 lbl_8059DC00;
extern const float lbl_805A1CA8;
void fn_8027CE3C(void*, int);
}

struct Glob {
    char pad[0x40];
    u8 a40;
    u8 a41;
};

template <class T>
struct Array {
    T* data;
    s32 size;
    u32 capacity;

    void push(const T& value) {
        if (size == (s32)(capacity & 0x3fffffff))
            fn_8027CE3C(this, sizeof(T));
        data[size++] = value;
    }
};

struct Self {
    char** unk0;
    s32 unk4;
    char pad8[0x24];
    s32 unk2C;
    s32 unk30;
    char pad34[0xe];
    u8 unk42;
    u8 unk43;
    char pad44[0x88];
    Array<s32> a;
    Array<u8> b;
};

extern "C" void fn_8008F084(Self* self, int a1, nw4r::g3d::ResMdl* mdl) {
    s32 off;
    s32 i = 0;
    off = 0;
    for (; i < self->unk4; off += 4, i++) {
        char* name = *(char**)((char*)self->unk0 + off) + 0x90;
        Glob* g = (Glob*)lbl_8049DEC8[0];
        if (g->a40 ? g->a41 : 0) {
            nw4r::g3d::ResNode r = mdl->GetResNode(name);
            s32 v = r.IsValid() ? r.ptr()->m_nodeIndex : 0;
            *(s32*)(*(char**)((char*)self->unk0 + off) + 0x1A0) = v;
        } else {
            nw4r::g3d::ResNode r = mdl->GetResNode(name);
            s32 v = r.IsValid() ? r.ptr()->m_nodeIndex : 0;
            *(s32*)(*(char**)((char*)self->unk0 + off) + 0x1A0) = v;
        }
        if (*(u8*)(*(char**)((char*)self->unk0 + off) + 0x1A8))
            self->unk2C = i;
        if (*(s32*)(*(char**)((char*)self->unk0 + off) + 0x200) == 0)
            self->unk30 = i;
        if (lbl_805A1CA8 == *(float*)(*(char**)((char*)self->unk0 + off) + 0xB0)) {
            self->a.push(i);
            self->b.push(lbl_8059DC00);
        }
    }
    self->unk42 = (u8)self->unk4;
    self->unk43 = (u8)self->unk4;
}