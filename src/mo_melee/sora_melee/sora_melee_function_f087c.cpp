#pragma force_active on
struct Entry {
    int unused;
    int id;
};

class Array {
public:
    virtual ~Array();
    virtual Entry* select(int);
    virtual Entry* at(int);
};

class Object {
public:
    virtual ~Object();
    virtual void unused1();
    virtual void unused2();
    virtual void unused3();
    virtual int size();

    int find(int id) {
        if (id <= -1)
            return -1;

        int count = size();
        for (int i = 0; i < count; ++i) {
            if (id == array.at(i)->id)
                return i;
        }
        return -1;
    }

    char padding[12];
    Array array;
};

extern "C" void fn_27_F087C(Object* self, int id) {
    if (id <= -1) {
        self->array.select(0);
        return;
    }

    int index = self->find(id);
    if (index < 0) {
        self->array.select(0);
        return;
    }

    self->array.select(index);
}
