#include <em/em_manager.h>
#include <so/so_external_value_accesser.h>
#pragma force_active on

extern "C" {

StageObject* fn_41_237A8(int);
extern char __RTTI__5Enemy[];
extern char __RTTI__11StageObject[];
void* __dynamic_cast(void*, long, const void*, const void*, short);
unsigned int fn_41_D044(emManager*, unsigned int);

int fn_41_23BD4(void* acc, int kind) {
    unsigned int id;
    int result = -1;

    if ((unsigned int)kind <= 3) {
        StageObject* obj = fn_41_237A8(kind);
        if (obj == 0)
            return -1;
        result = soExternalValueAccesser::getStatusKind(obj);
        return result;
    }

    if ((unsigned int)(kind - 4) <= 1) {
        void* obj = __dynamic_cast(
            *(void**)((char*)acc + 8),
            0x3c,
            __RTTI__5Enemy,
            __RTTI__11StageObject,
            1);
        id = *(unsigned int*)((char*)obj + 0xb0);

        if (kind == 4) {
            result = soExternalValueAccesser::getStatusKind((StageObject*)obj);
        } else if (kind == 5) {
            unsigned int r = fn_41_D044(emManager::getInstance(), id);
            if (r == 0xffff)
                return -1;

            Enemy* enemy = emManager::getInstance()->getEnemyPtrFromId(r);
            if (enemy == 0)
                return -1;
            result = soExternalValueAccesser::getStatusKind(enemy);
        }
        return result;
    }

    if (kind == 6)
        result = -1;
    else
        return -1;
    return result;
}

}