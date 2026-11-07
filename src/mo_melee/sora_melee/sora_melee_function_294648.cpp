#pragma force_active on

struct Entry {
    int unused;
    int id;
};

class Object_vptr_10 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual Entry& slot2(int);
};

class soNullable {
public:
    virtual void isNull();
    virtual void fn_27_2944E4();
    virtual void fn_27_2945E4();
    virtual void fn_27_294940();
    virtual int fn_27_294638();

    char padding[12];
    Object_vptr_10 array;

    int find(int id) {
        if (id <= -1)
            return -1;

        int count = fn_27_294638();
        for (int i = 0; i < count; ++i) {
            if (id == array.slot2(i).id)
                return i;
        }
        return -1;
    }
};

extern "C" int fn_27_294648(soNullable* self, int id) {
    int index = self->find(id);
    return (static_cast<unsigned int>(index) >> 31) ^ 1;
}
