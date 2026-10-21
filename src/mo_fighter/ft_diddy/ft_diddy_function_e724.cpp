#pragma force_active on
struct WorkModule {
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
    virtual void v18();
    virtual void v19();
    virtual void v20(unsigned long);
};

struct ItemInfo {
    char padding[0x28];
    int value;
};

struct Modules {
    char padding[0x64];
    WorkModule* work;
};

struct Accesser {
    char padding0[8];
    ItemInfo* item;
    char padding1[0xcc];
    Modules* modules;
};

extern "C" {
void* getInstance__9itManagerFv();
int getItemNum__9itManagerF6itKindiii(void*, int, int, int, int);
int getConstantInt__15soValueAccesserFP16soModuleAccesserUlUl(
    Accesser*, unsigned long, unsigned long);

void fn_115_E724(void*, Accesser* accesser) {
    int value = accesser->item->value;
    void* manager = getInstance__9itManagerFv();
    int count = getItemNum__9itManagerF6itKindiii(manager, 2, 0, value, -1);
    if (count < getConstantInt__15soValueAccesserFP16soModuleAccesserUlUl(
                    accesser, 0x5dc2, 0)) {
        accesser->modules->work->v20(0x22000015);
    }
}
}
