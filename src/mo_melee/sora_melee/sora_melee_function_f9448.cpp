#pragma force_active on

struct Entry {
    int unused;
    int id;
};

class Class_24660 {
public:
    virtual void fn_27_F9D00();
    virtual void fn_27_F9CB8();
    virtual Entry& fn_27_F9D30(int);
    virtual void fn_27_F9CD8();
    virtual void fn_27_F9CEC();
};

class soNullable {
public:
    virtual void isNull();
    virtual void fn_27_F92F4();
    virtual void fn_27_F93F4();
    virtual void fn_27_F9740();
    virtual int fn_27_D9DF4();

    char padding[12];
    Class_24660 array;

    int find(int id) {
        if (id <= -1)
            return -1;

        int count = fn_27_D9DF4();
        for (int i = 0; i < count; ++i) {
            if (id == array.fn_27_F9D30(i).id)
                return i;
        }
        return -1;
    }
};

extern "C" int fn_27_F9448(soNullable* self, int id) {
    int index = self->find(id);
    return (static_cast<unsigned int>(index) >> 31) ^ 1;
}
