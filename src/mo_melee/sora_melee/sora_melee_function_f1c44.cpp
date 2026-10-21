#pragma force_active on
struct Entry {
    int unused;
    int id;
};

class Array {
public:
    virtual void unused();
    virtual void select(int index);
    virtual Entry& at(int index);
};

class Object {
public:
    virtual void unused0();
    virtual void unused1();
    virtual void unused2();
    virtual void unused3();
    virtual int size();

    char padding[12];
    Array array;

    int find(int id) {
        if (id <= -1)
            return -1;

        int count = size();
        for (int i = 0; i < count; ++i) {
            if (id == array.at(i).id)
                return i;
        }
        return -1;
    }
};

extern "C" void fn_27_F1C44(Object* self, int id) {
    if (id <= -1) {
        self->array.select(0);
    } else {
        int index = self->find(id);
        if (index < 0)
            self->array.select(0);
        else
            self->array.select(index);
    }
}
