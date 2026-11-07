#pragma force_active on

struct Entry {
    int unused0;
    int id;
};

class Class_Arr {
public:
    virtual void s0();
    virtual void s1();
    virtual Entry& get(int);
    virtual void s3();
    virtual void s4();
};

class soNullable {
public:
    virtual void isNull();
    virtual void fn_27_1C0014();
    virtual void fn_27_1C0114();
    virtual void fn_27_1C0460();
    virtual int fn_27_1B14C8();

    char padding[12];
    Class_Arr array;

    int find(int id) {
        if (id <= -1)
            return -1;

        int count = fn_27_1B14C8();
        for (int i = 0; i < count; ++i) {
            if (id == array.get(i).id)
                return i;
        }
        return -1;
    }
};

extern "C" int fn_27_1C0168(soNullable* self, int id) {
    int index = self->find(id);
    return (static_cast<unsigned int>(index) >> 31) ^ 1;
}
