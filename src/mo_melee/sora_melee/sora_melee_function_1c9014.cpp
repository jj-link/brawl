#pragma force_active on

struct Element {
    int field0;
    int field4;
};

class Owner {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual unsigned int second();

    char pad[12];
    class Inner {
    public:
        virtual void slot0();
        virtual void slot1();
        virtual Element* get(int index);
        virtual int end();
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
        virtual unsigned int count();
    } inner1;
};

extern "C" int fn_27_1C9014(Owner* self) {
    if (self->inner1.count() == 1U) {
        return 0x7fff;
    }
    if (self->second() == 1U) {
        return 0;
    }

    int idx = self->inner1.end() - 1;
    if (self->inner1.get(idx)->field4 < 0x7fff) {
        idx = self->inner1.end() - 1;
        return self->inner1.get(idx)->field4 + 1;
    }

    int prev_val;
    int i = self->inner1.end() - 1;
    while (i >= 0) {
        if (i == 0) {
            if (self->inner1.get(i)->field4 == 0) {
                return -1;
            }
            return self->inner1.get(i)->field4 - 1;
        }

        prev_val = self->inner1.get(i - 1)->field4;
        Element* cur = self->inner1.get(i);
        if (cur->field4 - 1 > prev_val) {
            return self->inner1.get(i)->field4 - 1;
        }
        i--;
    }

    return -1;
}
