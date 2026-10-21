#pragma force_active on

extern "C" float lbl_27_rodata_7D90;

struct Work {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual int getInt(unsigned int);
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
    virtual int isFlag(unsigned int);
    virtual void onFlag(unsigned int);
    virtual void offFlag(unsigned int);
};

struct Request {
    int kind;
    bool flag;
    float value;
    int id;
    bool flag2;
};

struct Status {
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
    virtual void change(int, Request*, int);
};

struct Modules {
    char pad[0x54];
    Status* status;
    char pad2[0xc];
    Work* work;
};

struct Object {
    char pad[0xd8];
    Modules* modules;
};

extern "C" void fn_27_396F14(void*, Object* object) {
    if (object->modules->work->isFlag(0x22000015)) {
        object->modules->work->onFlag(0x22000016);
        object->modules->work->offFlag(0x22000015);

        Request request;
        request.kind = 0x17;
        request.flag = false;
        request.value = lbl_27_rodata_7D90;
        request.flag2 = false;
        request.id = object->modules->work->getInt(0x20000004);

        object->modules->status->change(0, &request, 0);
    }
}
