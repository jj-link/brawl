#pragma force_active on
struct LinkEvent {
    int id;
    unsigned char flag;
};

struct VtA {
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7(unsigned long, unsigned long);
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15(unsigned long);
    virtual void v16();
    virtual void v17();
    virtual void v18(int, LinkEvent*, unsigned long);
    virtual int v19(unsigned long);
    virtual void v20(unsigned long);
    virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24(); virtual void v25();
    virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29(); virtual void v30();
    virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35();
    virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39(); virtual void v40();
    virtual void v41(unsigned long);
};

struct VtB {
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
    virtual int v18();
};

struct ItemInfo {
    char pad0[0x28];
    int value;
};

struct Modules {
    char pad0[0x54];
    VtA* p54;
    char pad1[0xc];
    VtA* p64;
    char pad2[0x8];
    VtB* p70;
    char pad3[0x14];
    VtA* p88;
};

struct Accesser {
    char pad0[0x8];
    ItemInfo* item;
    char pad1[0xcc];
    Modules* modules;
};

extern "C" {
void* getInstance__9itManagerFv();
int getItemNum__9itManagerF6itKindiii(void*, int, int, int, int);
int getConstantInt__15soValueAccesserFP16soModuleAccesserUlUl(Accesser*, unsigned long, unsigned long);
float getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(Accesser*, unsigned long, unsigned long);

void fn_120_FAA8(void*, Accesser* accesser) {
    switch (accesser->modules->p70->v18()) {
    case 0x115: {
        VtA* obj = accesser->modules->p64;
        getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(accesser, 0xfcf, 0);
        obj->v15(0x21000004);
        int itemValue = accesser->item->value;
        void* inst = getInstance__9itManagerFv();
        int count = getItemNum__9itManagerF6itKindiii(inst, 0x57, 0, itemValue, -1);
        if (count < getConstantInt__15soValueAccesserFP16soModuleAccesserUlUl(accesser, 0x5dc7, 0)) {
            accesser->modules->p64->v7(0x1da, 0x20000001);
            accesser->modules->p64->v7(0x1e0, 0x20000002);
        } else {
            accesser->modules->p64->v7(0x1db, 0x20000001);
            accesser->modules->p64->v7(0x1e1, 0x20000002);
            accesser->modules->p64->v20(0x22000013);
        }
        break;
    }
    case 0x11b: {
        LinkEvent ev;
        ev.id = 0x839;
        ev.flag = 0;
        accesser->modules->p54->v18(-1, &ev, 0);
        break;
    }
    case 0x11c: {
        LinkEvent ev;
        ev.id = 0x83a;
        ev.flag = 0;
        accesser->modules->p54->v18(-1, &ev, 0);
        break;
    }
    case 0x11d: {
        LinkEvent ev;
        ev.id = 0x83b;
        ev.flag = 0;
        accesser->modules->p54->v18(-1, &ev, 0);
        if (accesser->modules->p64->v19(0x22000013)) {
            accesser->modules->p64->v7(0x1df, 0x20000001);
            accesser->modules->p64->v7(0x1e5, 0x20000002);
        } else {
            accesser->modules->p64->v7(0x1de, 0x20000001);
            accesser->modules->p64->v7(0x1e4, 0x20000002);
        }
        accesser->modules->p88->v41(0x1a);
        break;
    }
    }
}
}
