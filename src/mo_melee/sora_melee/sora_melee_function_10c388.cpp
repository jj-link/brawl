#pragma force_active on
class ftEntryManager {
public:
    void* getEntity(unsigned long id);
};

extern "C" void fn_27_11699C(void* entity, unsigned long arg, int flag);

extern "C" void fn_27_10C388(void* self, unsigned long id, unsigned long arg) {
    ftEntryManager* mgr = *(ftEntryManager**)((char*)self + 0x154);
    void* entity = mgr->getEntity(id);
    fn_27_11699C(entity, arg, 1);
}
