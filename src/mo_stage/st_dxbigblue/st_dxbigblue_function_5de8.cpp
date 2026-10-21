#pragma force_active on
typedef unsigned char u8;
typedef unsigned long u32;

struct Object;
typedef void (*Method)(Object*, const char*);

struct VTable {
    unsigned char pad0[0xB0];
    Method first;
    unsigned char pad1[0x8C];
    Method second;
};

struct Task {
    unsigned char pad0[0x3C];
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual void slot21();
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
    virtual void slot32();
    virtual void slot33();
    virtual void slot34();
    virtual void slot35();
    virtual void slot36();
    virtual void slot37();
    virtual void slot38();
    virtual void slot39();
    virtual void slot40();
    virtual void slot41();
    virtual void first(const char*);
    virtual void gap0();
    virtual void gap1();
    virtual void gap2();
    virtual void gap3();
    virtual void gap4();
    virtual void gap5();
    virtual void gap6();
    virtual void gap7();
    virtual void gap8();
    virtual void gap9();
    virtual void gap10();
    virtual void gap11();
    virtual void gap12();
    virtual void gap13();
    virtual void gap14();
    virtual void gap15();
    virtual void gap16();
    virtual void gap17();
    virtual void gap18();
    virtual void gap19();
    virtual void gap20();
    virtual void gap21();
    virtual void gap22();
    virtual void gap23();
    virtual void gap24();
    virtual void gap25();
    virtual void gap26();
    virtual void gap27();
    virtual void gap28();
    virtual void gap29();
    virtual void gap30();
    virtual void gap31();
    virtual void gap32();
    virtual void gap33();
    virtual void gap34();
    virtual void second(const char*);
};

struct Object {
    unsigned char pad0[0x3C];
    VTable* vtable;
    unsigned char pad1[0x128];
    u8 flag168;
    u8 flag169;
    unsigned char pad2[2];

    Object(const char* name);
};

struct GameMode {
    unsigned char pad0[8];
    u8 mode : 6;
    u8 unused : 2;
    unsigned char pad1[7];
    u8 stage;
};

struct GameGlobal {
    unsigned char pad0[8];
    GameMode* mode;
};

extern "C" {
void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
void fn_81_4E8C(Object*, const char*);
extern VTable lbl_81_data_1680;
extern GameGlobal* g_GameGlobal;
}

inline Object::Object(const char* name) {
    Object* obj = this;
    fn_81_4E8C(obj, name);
    *(VTable**)((unsigned char*)obj + 0x3C) = &lbl_81_data_1680;
    obj->flag168 = 1;
    obj->flag169 = 0;

    GameMode* mode = g_GameGlobal->mode;
    if (!mode) return;
    if (mode->mode != 7) return;
    if (mode->stage == 0x9F) obj->flag169 = 1;
    return;
}

namespace Heaps {
    enum HeapType { Stage = 15 };
}

void* operator new(unsigned long, Heaps::HeapType);

extern "C" Object* fn_81_5DE8(const char* a, const char* b, const char* name) {
    Object* obj = new(Heaps::Stage) Object(name);
    if (obj) {
        ((Task*)obj)->first(a);
        ((Task*)obj)->second(b);
    }
    return obj;
}
