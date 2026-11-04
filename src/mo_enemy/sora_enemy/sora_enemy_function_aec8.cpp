#include <em/em_manager.h>
#include <st/st_trigger.h>
#pragma force_active on
extern "C" bool fn_41_CEF0();
extern "C" unsigned int fn_27_2331C4(void*, int);
extern "C" int fn_27_233208(void*, int, int);

extern "C" bool fn_41_AEC8(void* self, int id, int index) {
    emManager::getInstance();
    if (!fn_41_CEF0())
        return false;
    unsigned int count = fn_27_2331C4(g_stTriggerMng, id);
    if (!count)
        return false;
    if (index == -1) {
        for (unsigned int i = 0; i < count; ++i) {
            if (!fn_27_233208(g_stTriggerMng, id, i))
                return false;
        }
    } else {
        if (!fn_27_233208(g_stTriggerMng, id, index))
            return false;
    }
    return true;
}