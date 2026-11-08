#pragma force_active on

struct Entry {
    int unused;
    int id;
};

class Class_15DB8 {
public:
    virtual void fn_27_AC9D8();
    virtual void fn_27_AC37C();
    virtual Entry& fn_27_AC38C(int);
};

class soNullable {
public:
    virtual void isNull();
    virtual void fn_27_1C09F8();
    virtual void fn_27_1C0AF8();
    virtual void fn_27_1C0E44();
    virtual int fn_27_1B14D8();

    char padding[12];
    Class_15DB8 array;

    int find(int id) {
        if (id <= -1)
            return -1;

        int count = fn_27_1B14D8();
        for (int i = 0; i < count; ++i) {
            if (id == array.fn_27_AC38C(i).id)
                return i;
        }
        return -1;
    }
};

extern "C" int fn_27_1C0B4C(soNullable* self, int id) {
    int index = self->find(id);
    return (static_cast<unsigned int>(index) >> 31) ^ 1;
}
