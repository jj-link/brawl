#pragma force_active on

struct WorkModule {
    virtual void unused0();
    virtual void unused1();
    virtual void unused2();
    virtual void unused3();
    virtual int getInt(int);
};

struct ModuleAccesser {
    char padding[0x64];
    WorkModule* work;
};

struct Enemy {
    char padding[0x1B4];
    ModuleAccesser* modules;
};

struct Caller {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual int method3();
};

struct Sub {
    char pad[0x14];
    Caller* obj;
};

struct Item {
    char pad[0x1A4];
    Sub* sub;
};

extern "C" void* getInstance__9itManagerFv();
extern "C" void* getItemFromInstanceId__9itManagerFi(void*, int);

extern "C" int fn_41_B744(Enemy* enemy) {
    int id = enemy->modules->work->getInt(0x1000000F);
    if (id != 0) {
        Item* item = (Item*)getItemFromInstanceId__9itManagerFi(getInstance__9itManagerFv(), id);
        if (item != 0) {
            return item->sub->obj->method3();
        }
    }
    return 5;
}
