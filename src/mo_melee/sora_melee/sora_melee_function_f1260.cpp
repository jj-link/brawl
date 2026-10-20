#pragma force_active on
struct Entry {
    int unused;
    int id;
};

class Array {
public:
    virtual void unused();
    virtual void select(int);
    virtual Entry& at(int);
};

class Object {
public:
    virtual void unused0();
    virtual void unused1();
    virtual void unused2();
    virtual void unused3();
    virtual int size();

    char padding[12];
    Array elements;

    Array* array() { return &elements; }

    int find(int id) {
        if (id <= -1)
            return -1;

        int count = size();
        for (int i = 0; i < count; ++i) {
            if (elements.at(i).id == id)
                return i;
        }
        return -1;
    }
};

extern "C" void fn_27_F1260(Object* self, int id) {
    if (id <= -1) {
        self->elements.select(0);
    } else {
        int index = self->find(id);
        if (index < 0)
            self->elements.select(0);
        else
            self->elements.select(index);
    }
}
