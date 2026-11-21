#include <mu/mu_msg.h>

#pragma force_active on

struct Class_728_base {
    char pad[0x3c];
};

class Class_728 : public Class_728_base {
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
    virtual void slot23(int, int, int);
    virtual void slot24();
    virtual void fn_2_36914();
    virtual void fn_2_36908();
    virtual void fn_2_361C4(int, int);
};

class Obj {
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
    virtual void v11(void*, Obj*);
    virtual void v12();
    virtual void v13(void*);
};

struct Arg : Obj {
    char pad[0xe0];
    void* field;
};

struct Item {
    char pad[0x10];
    void* field;
};

struct Entry {
    char pad[0xec];
    unsigned char enabled;
};

struct Menu {
    char pad0[0x42];
    unsigned short mode;
    char pad44[0x5f4];
    int state;
    char pad63c[0x10];
    Item** objects;
    Obj** list;
    Arg* arg;
    Class_728* task;
    char pad65c[8];
    int field664;
    char pad668[4];
    int values[8];
    unsigned short a;
    unsigned short first;
    unsigned short b;
    char pad692[2];
    MuMsg* msg;
};

extern "C" {
extern void* g_GameGlobal;
extern const float lbl_2_rodata_660[];
extern char lbl_2_data_2328[];

void fn_2_19BCC(Menu*, int);
void fn_18_17B0(Menu*, int, int, float);
void fn_800B330C(Item*, void*, int);
int fn_8004D6C4(void*, int, char*);
Entry* fn_8004D138(void*, int);
int fn_8004D148(void*);
}

extern "C" void fn_2_18D20(Menu* self, Arg* arg)
{
    const float* const ro = lbl_2_rodata_660;

    self->arg = arg;
    self->field664 = 0;
    self->b = 0;
    self->first = 0;
    self->a = 0;
    self->state = 5;

    arg->v11(arg->field, self->list[0]);
    arg->v11(arg->field, self->list[1]);

    int offset;
    int i;
    for (i = 0, offset = 0; i < 4; i++, offset += 4) {
        self->list[0]->v13((*reinterpret_cast<Item**>((char*)self->objects + offset + 0xb0))->field);
        self->list[0]->v13((*reinterpret_cast<Item**>((char*)self->objects + offset + 0xc0))->field);
        self->list[0]->v13((*reinterpret_cast<Item**>((char*)self->objects + offset + 0xd0))->field);
        self->list[0]->v13((*reinterpret_cast<Item**>((char*)self->objects + offset + 0xe0))->field);
    }

    for (int i = 0; i < 8; i++) {
        self->values[i] = -1;
        fn_2_19BCC(self, i);
    }

    self->task->fn_2_361C4(0x16, 0x40);
    self->task->slot23(0x40, 0, 0);
    self->mode = 0;
    fn_800B330C(self->objects[0x2a], lbl_2_data_2328, 1);
    fn_800B330C(self->objects[0x2b], lbl_2_data_2328 + 0x14, 1);

    char text[0x18];
    for (int i = 0; i < 5; i++) {
        if (fn_8004D6C4(g_GameGlobal, i + self->first, text)) {
            if (fn_8004D138(g_GameGlobal, i + self->first)->enabled == 1) {
                fn_18_17B0(self, i + 0x44, 4, ro[1]);
            } else {
                fn_18_17B0(self, i + 0x44, 4, ro[2]);
            }
            self->msg->setFontColor(i, 0x80, 0x80, 0x80, 0xff);
            self->msg->printf(i, text);
        } else {
            fn_18_17B0(self, i + 0x44, 4, ro[3]);
        }
    }

    if (fn_8004D148(g_GameGlobal) > 5) {
        fn_18_17B0(self, 0x2b, 2, ro[2]);
    } else {
        fn_18_17B0(self, 0x2b, 2, ro[3]);
    }
}
