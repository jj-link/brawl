#pragma force_active on
typedef unsigned int u32;

struct UnkInner {
    virtual void unk0();
    virtual void* getItem(u32 idx);
    virtual void unk8();
    virtual u32 getCount();
};

struct UnkOuter {
    char pad[0x3C];
    UnkInner* unk3C;
};

extern u32 lbl_41_bss_1BC[3];

extern "C" {
void* fn_41_29818(UnkOuter* self, u32 idx) {
    if (idx >= self->unk3C->getCount()) {
        return lbl_41_bss_1BC;
    }
    return self->unk3C->getItem(idx);
}
}
