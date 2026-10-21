#include <types.h>
#pragma force_active on

namespace Heaps {
    enum HeapType { StageInstance = 0xF };
}

void* operator new(unsigned long size, Heaps::HeapType heap);

class grGimmickHitPointEffectData;

extern "C" void* fn_27_23697C(void* self, void* parent, grGimmickHitPointEffectData* data);

class stTriggerHitPointEffect {
public:
    u32 m_unk0;
    virtual void vf0();
    virtual ~stTriggerHitPointEffect();
    u8 m_pad[0x40 - 0x08];
};

class stTrigger {
public:
    stTriggerHitPointEffect* setHitPointEffectTrigger(grGimmickHitPointEffectData* data);
    u8 m_pad0[0x18];
    stTriggerHitPointEffect* m_hitPointEffect;
    u8 m_pad1[0x2c - 0x1c];
    u8 m_sub[0x10];
};

stTriggerHitPointEffect* stTrigger::setHitPointEffectTrigger(grGimmickHitPointEffectData* data) {
    stTriggerHitPointEffect* effect = static_cast<stTriggerHitPointEffect*>(operator new(0x40, Heaps::StageInstance));
    if (effect) {
        effect = static_cast<stTriggerHitPointEffect*>(fn_27_23697C(effect, &m_sub, data));
    }
    if (m_hitPointEffect) {
        delete m_hitPointEffect;
    }
    m_hitPointEffect = effect;
    return effect;
}
