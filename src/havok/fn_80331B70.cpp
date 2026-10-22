#pragma force_active on
typedef signed int s32;
typedef unsigned int u32;

extern "C" void fn_8027CE3C(void* self, int n);

struct Entry {
    s32 unk0;
    s32 unk4;
};

struct Ctx {
    Entry* unk0;
    s32 unk4;
    u32 unk8;
    char pad[0xC];
    s32 unk18;
    bool full() const { return unk4 == (s32)(unk8 & 0x3FFFFFFF); }
};

extern "C" {
s32 fn_80331B70(Ctx* self) {
    s32 var = self->unk18;
    if (var != -1) {
        self->unk18 = self->unk0[var].unk4;
    } else {
        var = self->unk4;
        if (self->full()) {
            fn_8027CE3C(self, 8);
        }
        self->unk4++;
    }
    return var;
}
}
