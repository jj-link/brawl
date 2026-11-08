#pragma force_active on

struct Entry {
    int unused0;
    int id;
};

class Class_F6D8C {
public:
    virtual void fn_27_AC9D8();
    virtual void fn_27_AC37C();
    virtual Entry& fn_27_AC38C(int);
    virtual void fn_27_10094();
    virtual void fn_27_100C8();
};

class soNullable {
public:
    virtual void isNull();
    virtual void fn_27_F6B64();
    virtual void fn_27_F6C64();
    virtual void fn_27_F6FB0();
    virtual int fn_27_D9DB4();

    char padding[12];
    Class_F6D8C array;

    int find(int id) {
        if (id <= -1)
            return -1;

        int count = fn_27_D9DB4();
        for (int i = 0; i < count; ++i) {
            if (id == array.fn_27_AC38C(i).id)
                return i;
        }
        return -1;
    }
};

extern "C" int fn_27_F6CB8(soNullable* self, int id) {
    int index = self->find(id);
    return (static_cast<unsigned int>(index) >> 31) ^ 1;
}
