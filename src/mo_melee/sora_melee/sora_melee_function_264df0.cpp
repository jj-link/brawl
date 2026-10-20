#pragma force_active on
struct ftManager;

extern "C" {
extern ftManager* g_ftManager;

int getEntryIdFromTaskId__9ftManagerFiPi(ftManager*, int, int*);
int getPlayerNo__9ftManagerFi(ftManager*, int);

signed char getPlayerNumber__10grYakumonoFPi(void*, int* __restrict taskId) {
    int id = *taskId;
    ftManager* manager = g_ftManager;
    int entryId = getEntryIdFromTaskId__9ftManagerFiPi(manager, id, 0);
    if (entryId == -1)
        return -1;

    int playerNo = getPlayerNo__9ftManagerFi(manager, entryId);
    return playerNo < 4 ? (signed char)playerNo : -1;
}
}
