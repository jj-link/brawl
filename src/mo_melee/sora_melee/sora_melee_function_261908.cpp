#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;

struct Ground {
    u8 padding[0x4C];
    void* m_collision;
    u8 padding50[0x1C];
    u8 : 2;
    u8 valid : 1;
    u8 effect : 1;
    u8 : 4;
};

extern "C" void fn_80110B98(void*, u32, Ground*);

extern "C" void fn_27_261908(Ground* self, u32 effect) {
    self->effect = effect;
    if (self->m_collision) {
        if (self->effect && self->valid)
            fn_80110B98(self->m_collision, 1, self);
        else
            fn_80110B98(self->m_collision, 0, self);
    }
}
