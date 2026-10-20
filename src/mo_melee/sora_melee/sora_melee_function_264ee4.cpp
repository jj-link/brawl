#pragma force_active on

struct ftManager;

struct grCollStatus {
    char pad[0x10];
    int taskId;
};

struct gfTask {
    char pad[0x28];
    int taskId;
};

extern "C" {
extern ftManager* g_ftManager;

gfTask* getTask__6gfTaskFi(int);
int getEntryIdFromTaskId__9ftManagerFiPi(ftManager*, int, int*);
int getPlayerNo__9ftManagerFi(ftManager*, int);

signed char getPlayerNumber__10grYakumonoFP12grCollStatus(
    void*, grCollStatus* __restrict status)
{
    gfTask* task = getTask__6gfTaskFi(status->taskId);
    ftManager* manager = g_ftManager;
    int entryId = getEntryIdFromTaskId__9ftManagerFiPi(manager, task->taskId, 0);
    if (entryId == -1)
        return -1;

    int playerNo = getPlayerNo__9ftManagerFi(manager, entryId);
    return playerNo < 4 ? (signed char)playerNo : -1;
}
}
