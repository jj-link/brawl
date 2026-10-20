#include <types.h>
#pragma force_active on

struct ftManager;

extern "C" {
extern ftManager* g_ftManager;
int getPlayerNo__9ftManagerFi(ftManager*, int);
}

extern "C" int fn_27_2D8AC4(void* self, int entryId) {
    return getPlayerNo__9ftManagerFi(g_ftManager, entryId);
}
