#pragma force_active on
struct Entry {
    int unused;
    int id;
};

class Array {
public:
    virtual ~Array();
    virtual void select(int index);
    virtual Entry& at(int index);
};

class Object {
public:
    virtual ~Object();
    virtual void unused0();
    virtual void unused1();
    virtual void unused2();
    virtual int size();

    int find(int id) {
        if (id <= -1)
            return -1;

        int count = size();
        for (int i = 0; i < count; ++i) {
            if (array.at(i).id == id)
                return i;
        }
        return -1;
    }

    char padding[12];
    Array array;
};

extern "C" void fn_27_F2628(Object* self, int id) {
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
