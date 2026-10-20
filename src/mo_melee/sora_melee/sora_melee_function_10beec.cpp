#pragma force_active on
typedef unsigned int u32;

struct Entry {
    char padding[0x28];
    void* object;
    char padding2[0x24];
    int alternateId;
};

struct Context {
    char padding[0x154];
    void* manager;
};

extern "C" Entry* getEntity__14ftEntryManagerFUl(void*, u32);
extern "C" void fn_27_112C4C(void*);

extern "C" void fn_27_10BEEC(Context* self, u32 id) {
    Entry* entry = getEntity__14ftEntryManagerFUl(self->manager, id);
    int alternateId = entry->alternateId;
    void* manager = self->manager;
    if (alternateId != -1) {
        id = alternateId;
    }
    fn_27_112C4C(getEntity__14ftEntryManagerFUl(manager, id)->object);
}
