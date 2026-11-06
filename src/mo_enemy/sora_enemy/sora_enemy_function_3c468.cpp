#pragma force_active on

class Class_M3C {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5(int);
    virtual int slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9(int, int);
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14(int);
};

class Class_M30 {
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
};

class Class_M70 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3(int, void*);
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
};

struct ModuleSet {
    char pad0[0x30];
    Class_M30* m30;
    char pad1[0x3c - 0x34];
    Class_M3C* m3c;
    char pad2[0x70 - 0x40];
    Class_M70* m70;
};

struct EnumStart {
    char pad0[0x3c];
    Class_M3C* m3c;
    char pad1[0x70 - 0x40];
    Class_M70* m70;
};

struct Accesser {
    char pad[0xd8];
    EnumStart* mD8;
};

struct Fighter {
    char pad0[0x60];
    Accesser* m60;
    char pad1[0x1b4 - 0x64];
    ModuleSet* m1b4;
};

struct Object {
    char pad0[0x28];
    int unk28;
    char pad1[0x3c - 0x2c];
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
    virtual void v11();
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
    virtual void v26();
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
    virtual int v39();
};

struct Event {
    int kind;
    unsigned char b4;
    unsigned char b5;
    char pad0[2];
    int value;
    char pad1[0x10];
    unsigned char b1c;
};

extern "C" void fn_41_51C4(void*, int);
extern "C" void fn_41_B8D4(void*, void*, int, void*, int);

extern "C" void fn_41_3C468(Fighter* self, Event* event, int arg2, Object* object, int arg4) {
    switch (event->kind) {
    case 8:
        if (self->m1b4->m3c->slot6() != 0 || object->v39() != 0) {
            break;
        }
        self->m1b4->m30->slot4();
        event->b4 = 1;
        event->b1c = 0;
        self->m60->mD8->m3c->slot5(object->unk28);
        self->m60->mD8->m70->slot3(0xC, self->m60);
        return;
    case 14:
        self->m60->mD8->m3c->slot14(0);
        self->m60->mD8->m3c->slot11();
        self->m60->mD8->m3c->slot9(1, 0);
        fn_41_51C4(self, 0);
        self->m60->mD8->m70->slot3(0xE, self->m60);
        return;
    case 9:
        self->m60->mD8->m3c->slot14(0);
        self->m60->mD8->m3c->slot11();
        self->m60->mD8->m3c->slot9(1, 0);
        fn_41_51C4(self, 0);
        self->m60->mD8->m70->slot3(0xE, self->m60);
        return;
    }
    fn_41_B8D4(self, event, arg2, object, arg4);
}
