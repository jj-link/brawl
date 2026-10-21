#pragma force_active on

struct Item;

struct Resources {
    char padding[0x28];
    int value;
};

struct Modules {
    char padding[8];
    Resources* resources;
};

class Object {
public:
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
    virtual unsigned int attach(Item*, int);
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void remove(Item*);
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual unsigned int test();

    char padding[0x64];
    Modules* modules;
};

extern "C" void* getInstance__9itManagerFv();

extern "C" Item* createItem__9itManagerF6itKindUliP16soResourceModuleUciii(
    void*, int, unsigned int, int, void*, unsigned char, int, int, int);

extern "C" bool fn_27_B9108(
    Object* self, int kind, unsigned int value, int arg)
{
    if (self->test() == 1)
        return false;

    Item* item = createItem__9itManagerF6itKindUliP16soResourceModuleUciii(
        getInstance__9itManagerFv(), kind, value,
        self->modules->resources->value, 0, 0, 0xFFFF, 0, 0xFFFF);

    if (item) {
        if (self->attach(item, arg) == 1)
            return true;

        self->remove(item);
    }

    return false;
}
