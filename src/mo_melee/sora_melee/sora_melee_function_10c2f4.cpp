#pragma force_active on
class ftEntryManager {
public:
    void* getEntity(unsigned long id);
};

extern "C" void fn_27_116578(void* entity, unsigned long id, int flag);

extern "C" void fn_27_10C2F4(char* self, unsigned long unused, unsigned long id) {
    ftEntryManager* mgr = *(ftEntryManager**)(self + 0x154);
    void* entity = mgr->getEntity(unused);
    fn_27_116578(entity, id, 1);
}
