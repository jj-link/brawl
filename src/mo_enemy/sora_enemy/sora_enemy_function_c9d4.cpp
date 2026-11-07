#include <em/em_manager.h>
#include <em/em_info.h>
#pragma force_active on

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual u32 slot1(int);
};

extern "C" int fn_41_D828(emManager*, int);
extern "C" int fn_41_D380(emManager*, int);
extern "C" int fn_41_CE10(emManager*);
extern "C" u8* fn_41_CD5C(emManager*, int);
extern "C" void* fn_41_70(int, emCreate*);
extern "C" void fn_41_C8D0(u8*);
extern "C" void fn_41_108(void*, emCreate*);

int emManager::createEnemy(emCreate* create) {
    int id;
    int kind;
    u8* entry;
    void* enemy;
    if (((Object_vptr_0*)emInfo::getInstance())->slot1(create->m_enemyKind) == 1)
        return -2;
    getPreloadArchiveCountFromKind(create->m_enemyKind);
    int index = fn_41_D828(this, create->m_enemyKind);
    if (index < 0)
        return -5;
    if (fn_41_D380(this, index) == 0)
        return -5;
    int slot = fn_41_CE10(this);
    if (slot < 0)
        return -3;
    entry = fn_41_CD5C(this, slot);
    if (entry == 0)
        return -3;
    id = *(int*)((u8*)this + 8);
    *(int*)((u8*)this + 8) = id + 1;
    enemy = fn_41_70(id, create);
    if (enemy == 0)
        return -4;
    kind = create->m_enemyKind;
    fn_41_C8D0(entry);
    *(void**)(entry + 0x14) = enemy;
    entry[0] = 1;
    *(int*)(entry + 4) = kind;
    *(int*)(entry + 8) = create->m_parentCreateId;
    *(int*)(entry + 0xc) = id;
    fn_41_108(enemy, create);
    return id;
}