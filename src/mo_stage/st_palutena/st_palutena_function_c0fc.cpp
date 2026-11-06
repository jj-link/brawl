#pragma force_active on
typedef unsigned int u32;
struct Flags { u32 pad; u32 flags; };
class Class_1898 {
public:
    virtual void fn_67_818C();
    virtual void fn_67_7654();
    virtual void fn_67_7664();
    virtual void fn_67_51C8();
    virtual void fn_67_4E88(int, int);
    Flags* data;
    u32 state;
};
struct Object_vptr_3c_base { char pad[0x3c]; };
class Object_vptr_3c : public Object_vptr_3c_base {
public:
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
    virtual void slot42(int);
    virtual void slot43();
    virtual void slot44();
    virtual void slot45();
    virtual void slot46();
    virtual void slot47();
    virtual void slot48();
    virtual void slot49();
    virtual void slot50();
    virtual void slot51();
    virtual void slot52();
    virtual void slot53();
    virtual void slot54();
    virtual void slot55();
    virtual void slot56();
    virtual void slot57();
    virtual void slot58();
    virtual void slot59();
    virtual void slot60();
    virtual void slot61();
    virtual void slot62();
    virtual void slot63();
    virtual void slot64();
    virtual void slot65();
    virtual void slot66();
    virtual void slot67();
    virtual void slot68();
    virtual void slot69();
    virtual void slot70();
    virtual void slot71();
    virtual void slot72();
    virtual void slot73();
    virtual void slot74();
    virtual void slot75();
    virtual void slot76();
    virtual void slot77();
    virtual void slot78(const char*);
};
struct Obj {
    Obj(const char*);
    char pad0[0x3c];
    void* vtable;
    char pad40[0x90];
    char part[0xc];
    char paddc[0x7c];
    float x, y, z;
    unsigned char flag;
    float last;
};
namespace Heaps { enum HeapType { StageInstance = 15 }; }
extern void* operator new(unsigned long, Heaps::HeapType);
extern "C" Obj* fn_67_2058(Obj*, const char*);
extern "C" char lbl_67_data_2C40[];
extern "C" const float lbl_67_rodata_1B8;
inline Obj::Obj(const char* name) {
    fn_67_2058(this, name);
    vtable = lbl_67_data_2C40;
    float zero = lbl_67_rodata_1B8;
    x = zero;
    y = zero;
    z = zero;
    flag = 1;
    last = zero;
    Class_1898* p = (Class_1898*)part;
    if (!p) return;
    p->state = 1;
    p->fn_67_4E88(0, 15);
    p->data->flags |= 0x10;
}
extern "C" Obj* fn_67_C0FC(int model, const char* node, const char* name) {
    Obj* obj = new (Heaps::StageInstance) Obj(name);
    if (obj) {
        ((Object_vptr_3c*)obj)->slot42(model);
        ((Object_vptr_3c*)obj)->slot78(node);
    }
    return obj;
}