#include <types.h>
#include <em/em_manager.h>
#pragma force_active on

extern "C" {
void* __dynamic_cast(void*, long, const void*, const void*, short);
extern char __RTTI__5Enemy[];
extern char __RTTI__11StageObject[];
extern const float lbl_41_rodata_D54;
void* fn_41_237A8(int);
float fn_27_8CAD0(void*);
unsigned int fn_41_D044(emManager*, unsigned int);
}

extern "C" float fn_41_23E0C(void* acc, unsigned long id) {
    float result = lbl_41_rodata_D54;
    int sid = (int)id;
    if (id <= 3) {
        void* fighter = fn_41_237A8(id);
        if (fighter == 0) {
            return result;
        } else {
            float r = fn_27_8CAD0(fighter);
            return r;
        }
    }
    if (id - 4 <= 1) {
        void* enemy = __dynamic_cast(*(void**)((char*)acc + 8), 0x3c,
                                    __RTTI__5Enemy, __RTTI__11StageObject, 1);
        int taskId = *(int*)((char*)enemy + 0xb0);
        if (sid == 4) {
            result = fn_27_8CAD0(enemy);
        } else if (sid == 5) {
            unsigned int parent = fn_41_D044(emManager::getInstance(), (unsigned int)taskId);
            if (parent == 0xffff) {
                return result;
            }
            Enemy* target = emManager::getInstance()->getEnemyPtrFromId(parent);
            if (target == 0) {
                return result;
            }
            result = fn_27_8CAD0(target);
        }
        return result;
    }
    if (sid == 6) {
        return lbl_41_rodata_D54;
    }
    if (sid == 7) {
        return lbl_41_rodata_D54;
    }
    return result;
}
