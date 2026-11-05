#pragma force_active on
class Node {
public:
    virtual void isNull();
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
};
class Array {
public:
    virtual void slot0();
    virtual Node*& at(int);
    virtual void slot2();
    virtual int size();
};
class Receiver {
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
    virtual void slot10(Node*&);
};
struct Owner {
    char pad[0x2c];
    Array* list;
};
extern "C" void fn_27_96F58(Owner* self, Receiver* receiver, int key, int mode) {
    switch (mode) {
    case 0:
        for (int i = 0; i < self->list->size(); ++i) {
            if (self->list->at(i)) {
                if (key == self->list->at(i)->slot6()) {
                    receiver->slot10(self->list->at(i));
                }
            }
        }
        break;
    case 1:
        for (int i = 0; i < self->list->size(); ++i) {
            if (self->list->at(i)) {
                if (key == self->list->at(i)->slot6()) {
                    receiver->slot10(self->list->at(i));
                    break;
                }
            }
        }
        break;
    case 2:
        for (int i = self->list->size() - 1; i >= 0; --i) {
            if (self->list->at(i)) {
                if (key == self->list->at(i)->slot6()) {
                    receiver->slot10(self->list->at(i));
                    break;
                }
            }
        }
        break;
    }
}