#pragma force_active on

typedef unsigned int u32;

struct Target {
    virtual void unused0();
    virtual void unused1();
    virtual void unused2();
    virtual void unused3();
    virtual void unused4();
    virtual void unused5();
    virtual void unused6();
    virtual void unused7();
    virtual void unused8();
    virtual void unused9();
    virtual void unused10();
    virtual void unused11();
    virtual void unused12();
    virtual void unused13();
    virtual void unused14();
    virtual void apply(int);
};

struct List;

struct ListInterface {
    virtual void unused();
    virtual Target** at(int);
};

struct ListVTable {
    char pad[0x0c];
    Target** (*at)(List*, int);
};

struct List {
    ListVTable* vtable;
    void* secondary;
    u32 flags;
    char storage[96];
};

struct Object {
    virtual void unused0();
    virtual void unused1();
    virtual void unused2();
    virtual void unused3();
    virtual void unused4();
    virtual void unused5();
    virtual void unused6();
    virtual void unused7();
    virtual void unused8();
    virtual void unused9();
    virtual void unused10();
    virtual void unused11();
    virtual void unused12();
    virtual void unused13();
    virtual void unused14();
    virtual void unused15();
    virtual void unused16();
    virtual void unused17();
    virtual int enabled();
    virtual void extra0();
    virtual void extra1();
    virtual void extra2();
    virtual void extra3();
    virtual void extra4();
    virtual void extra5();
    virtual void extra6();
    virtual void fill(List*, int, int);
};

extern "C" char lbl_27_data_90D0[];

extern "C" void fn_27_9483C(Object* self, int arg1, int arg2, int arg3)
{
    if (self->enabled()) {
        List list;
        list.vtable = (ListVTable*)lbl_27_data_90D0;
        list.secondary = lbl_27_data_90D0 + 0x48;
        list.flags &= 0x1fff;

        self->fill(&list, arg1, arg3);

        for (int i = 0; i < (int)((list.flags << 12) & 0xfe000000) >> 26; ++i) {
            Target* target = *((ListInterface*)&list)->at(i);
            target->apply(arg2);
        }
    }
}
