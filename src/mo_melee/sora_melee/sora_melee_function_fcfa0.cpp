#pragma force_active on

struct Entry {
    int unused0;
    int id;
};

class ArrayClass {
public:
    virtual void fn_27_xxx1();
    virtual void fn_27_xxx2();
    virtual Entry& fn_27_xxx3(int);
};

class soNullable {
public:
    virtual void isNull();
    virtual void fn_27_FCE4C();
    virtual void fn_27_FCF4C();
    virtual void fn_27_FD298();
    virtual int fn_27_D9E54();

    char padding[12];
    ArrayClass array;

    int find(int id) {
        if (id <= -1)
            return -1;

        int count = fn_27_D9E54();
        for (int i = 0; i < count; ++i) {
            if (id == array.fn_27_xxx3(i).id)
                return i;
        }
        return -1;
    }
};

extern "C" int fn_27_FCFA0(soNullable* self, int id) {
    int index = self->find(id);
    return (static_cast<unsigned int>(index) >> 31) ^ 1;
}
