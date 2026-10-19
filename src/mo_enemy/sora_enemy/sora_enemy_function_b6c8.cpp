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

extern "C" void* getInstance__9itManagerFv();
extern "C" void* getItemFromInstanceId__9itManagerFi(void*, int);
extern "C" int fn_27_28CCF0(void*, int);

extern "C" int fn_41_B6C8(Enemy* enemy) {
    WorkModule* work = enemy->modules->work;
    int id = work->getInt(0x1000000F);
    if (id != 0) {
        void* item = getItemFromInstanceId__9itManagerFi(
            getInstance__9itManagerFv(), id);
        if (item != 0) {
            return fn_27_28CCF0(item, 0x1000000E);
        }
    }
    return 0;
}
