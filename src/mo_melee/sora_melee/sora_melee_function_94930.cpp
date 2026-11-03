#pragma force_active on

class Node {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual int slot6();
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
    virtual void slot17(int);
};

class Array {
public:
    virtual void slot0();
    virtual Node*& at(int);
    virtual void slot2();
    virtual int size();
};

class Owner {
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
    virtual int slot18();
    char pad[0x28];
    Array* list;
};

extern "C" void fn_27_94930(Owner* self, int arg1, int arg2)
{
    if (self->slot18()) {
        for (int i = 0; i < self->list->size(); ++i) {
            if (self->list->at(i)) {
                if (arg1 == self->list->at(i)->slot6()) {
                    self->list->at(i)->slot17(arg2);
                }
            }
        }
    }
}
