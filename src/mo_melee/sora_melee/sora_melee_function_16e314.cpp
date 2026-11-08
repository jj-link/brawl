#pragma force_active on

class Object;
struct Modules;

class Module {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual int slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13(int, Modules*, float);
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18(int, Modules*);
    virtual void slot19(int);
    virtual void slot20();
    virtual void slot21(int, Object*);
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void slot25();
    virtual void slot26();
    virtual void slot27();
    virtual void slot28();
    virtual void slot29();
    virtual void slot30();
    virtual void slot31();
    virtual int slot32(int);
};

struct Modules {
    char pad0[0x14];
    Module* m14;
    char pad18[0x4c];
    Module* m64;
    char pad68[8];
    Module* m70;
    char pad74[8];
    Module* m7C;
};

class Object {
public:
    char pad[0xd8];
    Modules* modules;
};

extern "C" void fn_27_16AD28(void*, Object*);
extern "C" float lbl_27_rodata_21E8;

extern "C" void fn_27_16E314(void* self, Object* obj) {
    int r = obj->modules->m70->slot32(0);
    if (r == 0x4D) goto skip;
    if (r < 0x4D) {
        if (r == 0x4A) goto skip;
    } else {
        if (r == 0x54) goto skip;
    }
    obj->modules->m64->slot19(0x22000019);
    obj->modules->m64->slot19(0x2200001B);
    {
        Modules* mods = obj->modules;
        float f = lbl_27_rodata_21E8;
        mods->m64->slot13(0x21000009, mods, f);
    }
skip:
    fn_27_16AD28(self, obj);
    if (obj->modules->m14->slot3() == 0) {
        obj->modules->m7C->slot21(0x1E, obj);
        return;
    }
    obj->modules->m7C->slot21(0x1F, obj);
    {
        Modules* mods = obj->modules;
        mods->m64->slot18(0x2200001C, mods);
    }
}
