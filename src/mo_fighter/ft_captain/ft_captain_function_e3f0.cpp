#pragma force_active on
struct CaptainEvent {
    int id;
    unsigned char flag;
    int operation;
    float x, y, z;
    float lr;
    float angle;
    bool update;
    float previous[3];

    CaptainEvent(int kind, int op) : id(kind), flag(0), operation(op) {}
};

class LinkModule {
public:
    virtual void slot0() = 0;
    virtual void slot1() = 0;
    virtual void slot2() = 0;
    virtual void slot3() = 0;
    virtual void slot4() = 0;
    virtual void slot5() = 0;
    virtual void slot6() = 0;
    virtual void slot7() = 0;
    virtual void slot8() = 0;
    virtual void slot9() = 0;
    virtual void slot10() = 0;
    virtual void slot11() = 0;
    virtual void slot12() = 0;
    virtual void slot13() = 0;
    virtual void slot14() = 0;
    virtual void send(int, CaptainEvent*) = 0;
};

class CameraModule {
public:
    virtual void slot0() = 0;
    virtual void slot1() = 0;
    virtual void slot2() = 0;
    virtual void slot3() = 0;
    virtual void slot4() = 0;
    virtual void slot5() = 0;
    virtual void slot6() = 0;
    virtual void slot7() = 0;
    virtual void slot8() = 0;
    virtual void slot9() = 0;
    virtual void slot10() = 0;
    virtual void slot11() = 0;
    virtual void slot12() = 0;
    virtual void slot13() = 0;
    virtual void slot14() = 0;
    virtual void slot15() = 0;
    virtual void slot16() = 0;
    virtual void slot17() = 0;
    virtual void slot18() = 0;
    virtual void slot19() = 0;
    virtual void slot20() = 0;
    virtual void set(int) = 0;
};

class LastModule {
    char padding[8];

public:
    virtual void slot0() = 0;
    virtual void slot1() = 0;
    virtual void slot2() = 0;
    virtual void slot3() = 0;
    virtual void slot4() = 0;
    virtual void slot5() = 0;
    virtual void slot6() = 0;
    virtual void slot7() = 0;
    virtual void slot8() = 0;
    virtual void slot9() = 0;
    virtual void slot10() = 0;
    virtual void slot11() = 0;
    virtual void slot12() = 0;
    virtual void slot13() = 0;
    virtual void slot14() = 0;
    virtual void slot15() = 0;
    virtual void update() = 0;
};

struct Modules {
    char padding[0x54];
    LinkModule* link;
    char padding2[0x30];
    CameraModule* camera;
    char padding3[0x2c];
    LastModule* last;
};

struct Accesser {
    char padding[0xd8];
    Modules* modules;
};

struct Article {
    int task;
    int link;
};

extern "C" {
extern const float lbl_100_rodata_30[4];
extern Article* lbl_100_bss_268;
extern unsigned char* g_soWorld;

int fn_100_10794(Accesser*, void*);
void fn_100_FB5C(Accesser*, CaptainEvent*);
float getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(
    Accesser*, unsigned long, unsigned long);
float randf__Fv();
void fn_100_FF9C(int);
void fn_100_10B74(Accesser*);
void fn_100_FC20(Accesser*);
void fn_100_FCE0();
void fn_100_10518(Accesser*, int);
void fn_100_10288();
void fn_100_1046C();
void fn_100_F7F4();
}

extern "C" void fn_100_E3F0(void*, Accesser* accesser, void* arg) {
    const float* constants = lbl_100_rodata_30;

    if (fn_100_10794(accesser, arg)) {
        CaptainEvent first(0x44f, 2);
        fn_100_FB5C(accesser, &first);

        CaptainEvent position(0x44f, 6);
        position.x = constants[0];
        position.y = constants[1] +
            getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(
                accesser, 0xfbd, 0);
        position.z = constants[0];
        position.lr = constants[2];
        position.angle = constants[3] * randf__Fv();
        position.update = false;

        LinkModule* link = accesser->modules->link;
        link->send(lbl_100_bss_268->link, &position);

        CaptainEvent last(0x450, 11);
        fn_100_FB5C(accesser, &last);
        fn_100_FF9C(0);

        CameraModule* camera = accesser->modules->camera;
        camera->set(8);
        g_soWorld[0xd] = 0;
    } else {
        fn_100_10B74(accesser);
        fn_100_FC20(accesser);
        fn_100_FCE0();
        fn_100_10518(accesser, 0);
        fn_100_10288();
        fn_100_1046C();
        fn_100_F7F4();
    }

    LastModule* last = accesser->modules->last;
    last->update();
}
