#include <types.h>
#pragma force_active on

class wnemSimple;

extern "C" u32 fn_41_2C254(wnemSimple* w);

class emWeaponList {
public:
    virtual void unk8();
    virtual wnemSimple** get(int index);
    virtual void unk10();
    virtual void unk14();
    virtual int unk18();
    virtual void unk1C();
    virtual void unk20();
    virtual void unk24();
    virtual void unk28();
    virtual void unk2C();
    virtual void unk30();
    virtual void unk34();
    virtual void unk38();
    virtual int getCount();
};

class emWeaponManager {
public:
    virtual ~emWeaponManager();
    u8 _pad[0x260];
    emWeaponList m_list;

    wnemSimple* GetManagedWeapon(u32 taskId, u32 p2, u32 p3);
};

wnemSimple* emWeaponManager::GetManagedWeapon(u32 taskId, u32 p2, u32 p3) {
    wnemSimple* w;
    if (m_list.unk18() != 0) {
        return 0;
    }
    u32 found = 0;
    for (int i = 0; i < m_list.getCount(); i++) {
        w = *m_list.get(i);
        if (w != 0) {
            if (fn_41_2C254(w) == taskId) {
                if (p2 == 0xFFFF) {
                    if (found == p3) {
                        return w;
                    }
                    found++;
                } else if ((s32)p2 == *(s32*)((u8*)w + 0x21CC)) {
                    if (found == p3) {
                        return w;
                    }
                    found++;
                }
            }
        }
    }
    return 0;
}
