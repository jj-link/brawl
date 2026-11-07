#pragma force_active on

struct Entry {
    int unused;
    int id;
};

class Class_26650 {
public:
    virtual void fn_27_FBB84();
    virtual void fn_27_FBA84();
    virtual Entry& fn_27_FBB8C(int);
    virtual void fn_27_FBED8();
    virtual void fn_27_D9E3C();
};

class soNullable {
public:
    virtual void isNull();
    virtual void fn_27_FBA84();
    virtual void fn_27_FBB84();
    virtual void fn_27_FBED0();
    virtual int fn_27_D9E34();

    char padding[12];
    Class_26650 array;

    int find(int id) {
        if (id <= -1)
            return -1;

        int count = fn_27_D9E34();
        for (int i = 0; i < count; ++i) {
            if (id == array.fn_27_FBB8C(i).id)
                return i;
        }
        return -1;
    }
};

extern "C" int fn_27_FBBD8(soNullable* self, int id) {
    int index = self->find(id);
    return (static_cast<unsigned int>(index) >> 31) ^ 1;
}
