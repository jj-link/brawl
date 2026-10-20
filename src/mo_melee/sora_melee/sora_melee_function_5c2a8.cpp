#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;
typedef int s32;

struct gfSlowManager {
    static u32 requestSlow(u8 type);
};

struct fn27Obj {
    char pad[0x2c];
    u8 m_slowId;
    char pad2[3];
    s32 m_max;
};

extern "C" {
void fn_27_5C2A8(fn27Obj* self, s32 slowType, s32 val) {
    if (val > self->m_max) {
        self->m_max = val;
    }
    if (self->m_slowId == 0xff) {
        u32 r = gfSlowManager::requestSlow((u8)slowType);
        self->m_slowId = (u8)(r >> 24);
    }
}
}
