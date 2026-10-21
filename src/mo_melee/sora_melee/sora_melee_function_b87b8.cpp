#pragma force_active on
struct Item;

struct OwnerInfo {
    char pad[0x28];
    int taskId;
};

struct ModuleAccesser {
    char pad[8];
    OwnerInfo* modules;
};

struct Module {
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual unsigned int attach(Item*, int, int, bool);
    virtual void v2c();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3c();
    virtual unsigned int occupied(int);
    virtual void v44();
    virtual void v48();
    virtual void v4c();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5c();
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6c();
    virtual void remove(Item*);

    char pad[0x64];
    ModuleAccesser* accesser;
};

extern "C" void* getInstance__9itManagerFv();

extern "C" Item* createItem__9itManagerF6itKindUliP16soResourceModuleUciii(
    void*, int, unsigned int, int, void*, unsigned char, int, int, int);

extern "C" bool fn_27_B87B8(
    Module* self, int kind, unsigned int variation, int slot, int arg)
{
    if (self->occupied(slot) == 1U)
        return false;

    Item* item = createItem__9itManagerF6itKindUliP16soResourceModuleUciii(
        getInstance__9itManagerFv(), kind, variation,
        self->accesser->modules->taskId, 0, 0, 0xFFFF, 0, 0xFFFF);

    if (item) {
        if (self->attach(item, slot, arg, true) == 1U)
            return true;

        self->remove(item);
    }

    return false;
}
