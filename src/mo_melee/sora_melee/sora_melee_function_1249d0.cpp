#pragma force_active on
struct gfTask_base { char pad[0x3c]; };
class gfTask : public gfTask_base {
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
    virtual void processCamera();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void renderOpa();
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual void init();
    virtual ~gfTask();
};
struct Item {
    char pad[0x14];
    gfTask* task;
};
class soNullable {
public:
    virtual void isNull();
    virtual Item* slot1(int);
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
    virtual void slot12(int);
};
extern "C" void fn_27_1249D0(soNullable* self, gfTask* task) {
    for (int i = 0; i < self->slot3(); i++) {
        if (self->slot1(i)->task == task) {
            delete self->slot1(i)->task;
            self->slot12(i);
            return;
        }
    }
}