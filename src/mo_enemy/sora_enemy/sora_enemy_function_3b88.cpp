#pragma force_active on
typedef unsigned long u32;

class WorkModule {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual u32 getInt(u32 id);
};

struct ModuleAccesser {
    unsigned char padding[0x64];
    WorkModule* work;
};

struct ResourceInfo {
    unsigned char padding[0x10];
    u32 id;

    u32 getId() const { return id; }
};

class emResourceModuleImpl {
public:
    void* getInfoTexFile(u32, u32);
};

struct Enemy {
    unsigned char padding0[0x1B4];
    ModuleAccesser* modules;
    unsigned char padding1[0x91C - 0x1B8];
    ResourceInfo* info;
    unsigned char padding2[0x938 - 0x920];
    emResourceModuleImpl resources;
};

extern "C" void* getFaceTexPtr__5EnemyFv(Enemy* enemy) {
    u32 index = enemy->modules->work->getInt(0x10000017);
    u32 id = enemy->info->getId();
    return enemy->resources.getInfoTexFile(id, index);
}
