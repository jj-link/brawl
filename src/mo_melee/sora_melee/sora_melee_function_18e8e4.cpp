#pragma force_active on
#include <it/it_manager.h>
struct Id { int value; };
inline Id makeId(int value) { Id id; id.value = value; return id; }
struct ModuleAccesser;
struct WorkModule {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual int v4(int, void*);
};
struct ModuleAccesser { char pad[0x64]; WorkModule* work; };
struct SoraObj { char pad[0xD8]; ModuleAccesser* ma; };
extern "C" void fn_27_18E8E4(void*, SoraObj* self) {
    ModuleAccesser* ma = self->ma;
    int id = ma->work->v4(makeId(0x10000030).value, ma);
    if (id != 0) {
        BaseItem* item = itManager::getInstance()->getItemFromInstanceId(id);
        if (item != 0) {
            itManager::getInstance()->removeItem(item);
        }
    }
}