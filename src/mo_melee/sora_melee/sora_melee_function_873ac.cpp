#include <types.h>
#pragma force_active on

extern float lbl_27_rodata_B80;

class soKineticEnergy;

struct soAttributeFlag {
    s16 m_mask;
    soAttributeFlag(const soAttributeFlag&);
};

template <class T>
class soInstanceUnitFullProperty {
public:
    soAttributeFlag getAttribute() const;
};

struct Vec2 {
    float x;
    float y;
};

class soKineticEnergy_ {
public:
    virtual void v0();
    virtual void v1();
    virtual Vec2 getVec();
    u8 pad0[1];
    u8 m_flag;
};

class FullUnit {
public:
    soKineticEnergy_* m_element;
};

class Manager {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual s32 getCount();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual FullUnit* get(s32 index);
    virtual FullUnit* getFast(s32 index);
};

struct Owner {
    u8 pad[0x14];
    Manager* m_mgr;
};

extern "C" Vec2 fn_27_873AC(Owner* self, s16* mask) {
    Vec2 result;
    result.x = lbl_27_rodata_B80;
    result.y = lbl_27_rodata_B80;

    if (*mask == -1) {
        s32 i = self->m_mgr->getCount() - 1;
        while (i >= 0) {
            FullUnit* unit = self->m_mgr->get(i);
            soKineticEnergy_* elem = (soKineticEnergy_*)unit->m_element;
            if (((elem->m_flag >> 7) & 1) != 0) {
                Vec2 v = elem->getVec();
                result.x += v.x;
                result.y += v.y;
            }
            i--;
        }
    } else {
        s32 n = self->m_mgr->getCount();
        for (s32 i = 0; i < n; i++) {
            FullUnit* unit = self->m_mgr->getFast(i);
            soAttributeFlag attr =
                ((soInstanceUnitFullProperty<soKineticEnergy*>*)unit)->getAttribute();
            if (attr.m_mask & *mask) {
                soKineticEnergy_* elem = (soKineticEnergy_*)unit->m_element;
                if (((elem->m_flag >> 7) & 1) != 0) {
                    Vec2 v = elem->getVec();
                    result.x += v.x;
                    result.y += v.y;
                }
            }
        }
    }
    return result;
}
