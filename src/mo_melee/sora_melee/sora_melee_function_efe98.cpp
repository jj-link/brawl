#pragma force_active on
struct Entry {
    int unused;
    int id;
};

class Array {
public:
    virtual ~Array();
    virtual Entry& at(int);
    virtual Entry& get(int);
};

class Object {
public:
    virtual ~Object();
    virtual void unused0();
    virtual void unused1();
    virtual void unused2();
    virtual int size();

    char padding[12];
    Array array;

    int find(int id) {
        if (id <= -1)
            return -1;

        int count = size();
        for (int i = 0; i < count; ++i) {
            if (id == array.get(i).id)
                return i;
        }
        return -1;
    }
};

extern "C" Entry& fn_27_EFE98(Object* self, int id) {
    if (id <= -1)
        return self->array.at(0);

    int index = self->find(id);
    if (index < 0)
        return self->array.at(0);

    return self->array.at(index);
}
