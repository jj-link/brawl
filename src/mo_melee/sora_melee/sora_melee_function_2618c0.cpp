#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;

class Ground {
public:
    u8 pad00[0x4C];
    void* m_collision;
    u8 pad50[0x1C];
    u8 unused : 2;
    u8 enabled : 1;
    u8 effect : 1;
    u8 rest : 4;

    void setEnableCollisionStatus(bool enable);
};

extern "C" void fn_80110B98(void*, u32, Ground*);

void Ground::setEnableCollisionStatus(bool enable) {
    enabled = enable;
    if (m_collision) {
        if (enabled && effect)
            fn_80110B98(m_collision, 1, this);
        else
            fn_80110B98(m_collision, 0, this);
    }
}
