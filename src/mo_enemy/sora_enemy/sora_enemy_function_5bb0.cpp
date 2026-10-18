#pragma force_active on
typedef unsigned char u8;
typedef unsigned long u32;

class soModuleAccesser;

class itManager {
public:
    static void* getInstance();
};

class soValueAccesser {
public:
    static int getValueInt(soModuleAccesser* acc, u32 id, u32 idx);
};

struct IfaceVt {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual int v3();
};

extern "C" void fn_27_2A8714(void* p);

extern "C" bool fn_41_5BB0(u8* self) {
    IfaceVt* p = (IfaceVt*)((u8*)itManager::getInstance() + 0xce8);
    if (p->v3() <= 0) {
        return false;
    }
    int a = soValueAccesser::getValueInt((soModuleAccesser*)(self + 0xdc), 0x59e3, 0);
    ((IfaceVt*)((u8*)itManager::getInstance() + 0x6d8))->v3();
    fn_27_2A8714(itManager::getInstance());
    int b = ((IfaceVt*)((u8*)itManager::getInstance() + 0x6d8))->v3();
    return a > b;
}
