#pragma force_active on

struct Entry {
    int unused0;
    int id;
};

class Class_46E80 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual Entry& fn_27_1E4DA8(int);
    virtual void slot3();
    virtual void slot4();
};

class soNullable {
public:
    virtual void isNull();
    virtual void fn_27_1E4C70();
    virtual void fn_27_1E4D70();
    virtual void fn_27_1E50CC();
    virtual int fn_27_1E4DC4();

    char padding[12];
    Class_46E80 array;

    int find(int id) {
        if (id <= -1)
            return -1;

        int count = fn_27_1E4DC4();
        for (int i = 0; i < count; ++i) {
            if (id == array.fn_27_1E4DA8(i).id)
                return i;
        }
        return -1;
    }
};

extern "C" int fn_27_1E4DD4(soNullable* self, int id) {
    int index = self->find(id);
    return (static_cast<unsigned int>(index) >> 31) ^ 1;
}
