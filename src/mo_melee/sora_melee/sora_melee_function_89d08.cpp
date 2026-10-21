#pragma force_active on
struct UnknownEntry {
    unsigned char data[5];
    unsigned char flags;
};

struct UnknownObject {
    virtual void* slot0();
    virtual void* slot1();
    virtual void* slot2(void*);
    virtual void* slot3();
    virtual void* slot4();
    virtual void* slot5();
    virtual void* getEntry(void*);
};

struct UnknownManager {
    unsigned char pad[0x7C];
    UnknownObject* object;
};

struct UnknownContext {
    unsigned char pad[0xD8];
    UnknownManager* manager;
};

struct UnknownInterface {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void* call(void*, void*, void*, UnknownContext*);
};

extern "C" void fn_27_89D08(void* arg0, UnknownContext* context,
                           void* arg2, void* arg3, void* arg4) {
    UnknownEntry* entry =
        (UnknownEntry*)context->manager->object->getEntry(arg0);
    ((UnknownInterface*)entry)->call(arg2, arg3, arg4, context);
    entry = (UnknownEntry*)context->manager->object->getEntry(arg0);
    entry->flags |= 0x80;
}
