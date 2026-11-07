#pragma force_active on

struct Entry {
    int unused;
    int id;
};

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual Entry& slot2(int);
    virtual void slot3();
    virtual void slot4();
};

class soNullable {
public:
    virtual void isNull();
    virtual void fn_27_1CCFC8();
    virtual void fn_27_1CD0C8();
    virtual void fn_27_1CD414();
    virtual int fn_27_1B1618();

    char padding[12];
    Object_vptr_0 array;

    int find(int id) {
        if (id <= -1)
            return -1;

        int count = fn_27_1B1618();
        for (int i = 0; i < count; ++i) {
            if (id == array.slot2(i).id)
                return i;
        }
        return -1;
    }
};

extern "C" int fn_27_1CD11C(soNullable* self, int id) {
    int index = self->find(id);
    return (static_cast<unsigned int>(index) >> 31) ^ 1;
}