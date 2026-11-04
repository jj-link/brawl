#include <types.h>
#include <it/it_manager.h>
#pragma force_active on

extern "C" int fn_27_2C0E10(void* figMgr, u32 id);
extern "C" int fn_27_2C0FBC(void* figMgr, u32 id, int flag);

struct ModuleCallee {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18(u32, void*);
};

extern "C" void fn_27_29A278(void* unused, u8* self) {
    u32 id;
    void* figMgr = itManager::getInstance()->m_figureManager;
    id = *(u32*)(self + 0x8c4);
    u32 arg = (fn_27_2C0E10(itManager::getInstance()->m_figureManager, id) != 0) ? id : 1;
    if (fn_27_2C0FBC(figMgr, arg, 1) != 0) {
        u8* acc = *(u8**)(self + 0x60);
        ModuleCallee* c = *(ModuleCallee**)(*(u8**)(acc + 0xd8) + 0x64);
        c->v18(0x12000003, acc);
    }
}
