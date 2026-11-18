#pragma force_active on

struct Entry {
    char padding[0x28];
    int id;
};

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual Entry* slot1(int);
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual int slot5();
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
    virtual void slot42();
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
    virtual void slot58(int);
};

struct ModelData {
    char padding[0xe8];
    int value;
};

struct Class_90D8_base {
    char padding[8];
};

class Class_90D8 : public Class_90D8_base {
public:
    virtual void fn_27_7B274();
    virtual void fn_27_7AC18();
    virtual void fn_27_7AC28();
    virtual void fn_27_7AB50();
    virtual void fn_27_7B2EC();
    virtual void fn_27_7AB10();
    virtual void fn_27_7AD2C();
    virtual void fn_27_7AEDC();
    virtual void fn_27_7B22C();
    virtual void fn_27_7AC38();
    virtual void fn_27_7ADE8();
    virtual void fn_27_7AF98();
    virtual void fn_27_7B0B0();
    virtual ModelData* fn_27_7ABD8();
};

struct Modules {
    char padding[4];
    Class_90D8* model;
    char padding2[0xb8];
    Object_vptr_0* other;
};

struct Access {
    char padding[0xd8];
    Modules* modules;
};

struct Self {
    char padding[0x90];
    Object_vptr_0* array;
    char padding2[0xd4];
    Access* access;
};

struct Value {
    int x;
};

extern "C" void fn_27_20678(
    Entry*, Value, Value, int, int, int, int, float, float);
extern "C" void fn_27_1FE18(Entry*, ModelData*);

extern "C" void fn_27_17970(
    Self* self, int arg1, int arg2, int arg3, int arg4, float f1, float f2)
{
    Value a;
    a.x = arg1;
    Entry* entry = self->array->slot1(arg2);
    if (-1 != entry->id) {
        ((Object_vptr_0*)self)->slot58(arg2);
    }

    Modules* modules = self->access->modules;
    Object_vptr_0* other = modules->other;
    Value b;
    b.x = modules->model->fn_27_7ABD8()->value;
    fn_27_20678(entry, a, b, other->slot5(), arg4, 0, 0, f1, f2);
    fn_27_1FE18(entry, self->access->modules->model->fn_27_7ABD8());
    entry->id = arg3;
}
