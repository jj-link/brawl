#include <types.h>
#pragma force_active on

struct ftManager;

extern "C" {
extern ftManager* g_ftManager;
int getEntryIdFromTaskId__9ftManagerFiPi(ftManager*, int, int*);
int getPlayerNo__9ftManagerFi(ftManager*, int);
}

extern "C" void fn_27_27C000(void* self, void* unused, int* taskId) {
    ftManager* manager = g_ftManager;
    int entryId = getEntryIdFromTaskId__9ftManagerFiPi(manager, *taskId, 0);
    if (entryId != -1) {
        int playerNo = getPlayerNo__9ftManagerFi(manager, entryId);
        if (playerNo < 4) {
            *((u8*)self + 0x1EC + playerNo) = 1;
        }
    }
}
