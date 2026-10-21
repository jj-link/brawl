#include <types.h>
#pragma force_active on

class ftManager;

extern "C" {
extern ftManager* g_ftManager;
int getEntryIdFromTaskId__9ftManagerFiPi(ftManager*, int, int*);
void* getSubFighter__9ftManagerFi(ftManager*, int);
}

class Fighter {
    char _pad[0x28];
public:
    u32 m_taskId;
};

class grYakumono {
public:
    s32 isSubFighter(int* __restrict taskId);
};

s32 grYakumono::isSubFighter(int* __restrict taskId) {
    int task = *taskId;
    ftManager* manager = g_ftManager;
    int entryId = getEntryIdFromTaskId__9ftManagerFiPi(manager, task, 0);
    if (entryId == -1) {
        return 0;
    }
    Fighter* subFighter = static_cast<Fighter*>(getSubFighter__9ftManagerFi(manager, entryId));
    if (subFighter == 0) {
        return 0;
    }
    return __cntlzw(subFighter->m_taskId - *taskId) / 32u;
}
