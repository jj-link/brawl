#pragma force_active on
#pragma scheduling on

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void* slot4(int, int);
};

extern Object_vptr_0* lbl_805A0EB8;
extern "C" char lbl_80486870[];
extern "C" char lbl_804868AC[];

class Class_802A1FD4 {
public:
    static void operator delete(void* p);
};

struct Vtable_Class_802A8E1C {
    void* vtable;

    Vtable_Class_802A8E1C() : vtable(lbl_804868AC) {}
};

class Class_802A8E1C : public Vtable_Class_802A8E1C, public Class_802A1FD4 {
public:
    Class_802A8E1C(int);

    static void* operator new(unsigned long) {
        void* p = lbl_805A0EB8->slot4(0x40, 0x1d);
        ((unsigned short*)p)[2] = 0x40;
        return p;
    }
};

class Derived : public Class_802A8E1C {
public:
    Derived(int x) : Class_802A8E1C(x) {
        vtable = lbl_80486870;
    }

    static void* operator new(unsigned long) {
        Derived* p = (Derived*)lbl_805A0EB8->slot4(0x40, 0x1d);
        ((unsigned short*)p)[2] = 0x40;
        return p;
    }
};

struct Value {
    char pad[0x24];
    int value;
};

struct Entry {
    char pad[0x14];
    Value* value;
};

extern "C" Class_802A8E1C* fn_802A8F50(Entry* const& a, Entry* const& b, int unused, int x) {
    if (a->value->value < b->value->value) {
        return new Class_802A8E1C(x);
    } else {
        return new Derived(x);
    }
}
