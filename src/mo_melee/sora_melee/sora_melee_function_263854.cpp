#include <so/collision/so_collision.h>
#include <so/collision/so_collision_attack_module_impl.h>
#include <so/collision/so_collision_hit_module_impl.h>
#include <types.h>
#pragma force_active on

class Yakumono {
public:
    void setCollisionHitOpponentCategory(int unk1, bool unk2);
};

void Yakumono::setCollisionHitOpponentCategory(int unk1, bool unk2) {
    char* base = (char*)this;
    int i = 0;
    for (; i < *(int*)*(void**)(base + 0x188); i++) {
        soCollisionHitModule* module = *(soCollisionHitModule**)((char*)*(void**)(base + 0x180) + 0x20);
        module->setOpponentCategory((soCollision::CategoryMask)unk1, unk2, i);
    }
}
