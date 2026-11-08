#pragma force_active on

struct Entry {
    int unused;
    int id;
};

class Class_50A {
public:
    virtual void fn_27_508B0();
    virtual void fn_27_509B0();
    virtual Entry& fn_27_50D0C(int);
    virtual void fn_27_50A04();
    virtual void fn_27_50A10();
};

class soNullable {
public:
    virtual void isNull();
    virtual void fn_27_508B0();
    virtual void fn_27_509B0();
    virtual void fn_27_50D0C();
    virtual int fn_27_50A04();

    char padding[12];
    Class_50A array;

    int find(int id) {
        if (id <= -1)
            return -1;

        int count = fn_27_50A04();
        for (int i = 0; i < count; ++i) {
            if (id == array.fn_27_50D0C(i).id)
                return i;
        }
        return -1;
    }
};

extern "C" int fn_27_50A14(soNullable* self, int id) {
    int index = self->find(id);
    return (static_cast<unsigned int>(index) >> 31) ^ 1;
}
