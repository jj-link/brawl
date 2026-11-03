#pragma force_active on
#include <em/em_manager.h>
#include <types.h>

extern "C" void* fn_41_D044(void* mgr, u32 id);
extern "C" int fn_41_D0A8(void* mgr, void* task);
extern "C" void* fn_41_CECC(void* mgr, void* task);

struct emVirtObj {
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
    virtual void call(u32 id);
};

extern "C" void fn_41_B540(void* p) {
    void* task = fn_41_D044(emManager::getInstance(), *(u32*)((char*)p + 0xB0));
    if (fn_41_D0A8(emManager::getInstance(), task) == 0) {
        emVirtObj* obj = *(emVirtObj**)((char*)*(void**)((char*)*(void**)((char*)p + 0x60) + 0xD8) + 0x64);
        obj->call(0x1100000C);
    } else {
        void* node = fn_41_CECC(emManager::getInstance(), task);
        emVirtObj* obj = *(emVirtObj**)((char*)*(void**)((char*)*(void**)((char*)node + 0x60) + 0xD8) + 0x64);
        obj->call(0x1100000C);
    }
}
