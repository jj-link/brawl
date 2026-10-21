#pragma force_active on
typedef unsigned int u32;
typedef unsigned char u8;

struct grCollStatus {
    char pad[0x10];
    u32 taskId;
};

struct grCollisionJoint;

struct Task {
    char pad[0x2c];
    u32 flags;
};

struct grMadein {
    char pad[0x16c];
    u8 flags;
    char pad16d[0xb];
    u32 taskId;
};

extern "C" void* getInstance__15gfTaskSchedulerFv();
extern "C" Task* getTask__15gfTaskSchedulerFUl(void*, u32);

inline bool isValidTask(u32 id) {
    Task* task = getTask__15gfTaskSchedulerFUl(
        getInstance__15gfTaskSchedulerFv(), id);

    if (task != 0 &&
        ((int)((task->flags << 17) & 0xff800000) >> 24) != 11)
        return true;
    return false;
}

extern "C" void receiveCollMsg_Landing__8grMadeinFP12grCollStatusP16grCollisionJointb(
    grMadein* self, grCollStatus* status, grCollisionJoint*, bool) {
    u32 id = status->taskId;
    if ((self->flags & 1u) != 1u || isValidTask(id)) {
        self->taskId = id;
        self->flags |= 2;
    }
}
