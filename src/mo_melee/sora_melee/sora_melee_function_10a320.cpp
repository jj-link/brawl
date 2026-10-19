#pragma force_active on
struct ftEntryManager;

struct ftEntity {
    char pad[0x2c];
    void* field;
};

struct ftEntryManager {
    ftEntity* getEntity(unsigned long id);
};

struct Outer {
    char pad[0x154];
    ftEntryManager* mgr;
};

extern "C" void fn_27_1246D4(void* self, void* arg);

extern "C" void fn_27_10A320(Outer* self, unsigned long id, void* arg) {
    ftEntity* e = self->mgr->getEntity(id);
    fn_27_1246D4(e->field, arg);
}
