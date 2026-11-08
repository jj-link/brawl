#pragma force_active on

class AudMgr {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
};

struct AudHolder {
    char pad[8];
    AudMgr* mgr;
};

class Sub {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void m5(int entry, unsigned int flag);
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void m13(unsigned int flag, void* p);
    virtual void v14();
};

struct Owner2 {
    char pad[0x64];
    Sub* sub;
};

struct Owner {
    char pad[8];
    void* p8;
    char pad2[0xd8 - 0xc];
    Owner2* d8;
};

struct Task {
    char pad[0x40];
    int taskId;
};

struct CastResult {
    char pad[0x10c];
    int id;
};

class ftManager;
extern AudHolder* g_ftAudienceManager;
extern ftManager* g_ftManager;
extern "C" const char lbl_27_data_69C0[];
extern "C" const char lbl_27_data_248[];
extern "C" void* __dynamic_cast(void*, long, const void*, const void*, short);
extern "C" int getEntryIdFromTaskId__9ftManagerFiPi(ftManager*, int, int*);

extern "C" void fn_27_1521E8(void* self, Owner* owner, Task* task) {
    g_ftAudienceManager->mgr->v4();
    owner->d8->sub->m13(0x1100000E, owner->d8);
    int id = getEntryIdFromTaskId__9ftManagerFiPi(g_ftManager, task->taskId, 0);
    if (id == -1 || id != ((CastResult*)__dynamic_cast(owner->p8, 0x3c, lbl_27_data_69C0, lbl_27_data_248, 1))->id) {
        owner->d8->sub->m5(id, 0x1000003F);
    }
}
