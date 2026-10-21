#pragma force_active on

struct ObjectPrefix {
    unsigned char padding0[8];
    unsigned char active;
    unsigned char padding9[7];
};

struct Object : ObjectPrefix {
    virtual ~Object();
};

struct Container {
    virtual void slot0();
    virtual Object** at(int);
    virtual void slot2();
    virtual int size();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void remove(int);
};

struct Root {
    unsigned char padding[8];
    Container container;
};

extern "C" bool fn_27_2C2C18(Object*);

extern "C" bool fn_27_2C197C(Root* self) {
    int count = 0;
    for (int i = 0; i < self->container.size(); ++i) {
        Object** entry = self->container.at(i);
        Object* obj = *entry;
        if (obj != 0 && obj->active != 0) {
            ++count;
            if (fn_27_2C2C18(obj)) {
                delete *entry;
                self->container.remove(i);
                --i;
            }
        }
    }
    return count <= 0;
}
