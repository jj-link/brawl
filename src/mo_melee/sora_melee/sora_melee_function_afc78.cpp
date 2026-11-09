#pragma force_active on

struct Entry {
    int unused;
    int id;
};

class ArrayObj {
public:
    virtual void slot0();
    virtual void slot1();
    virtual Entry& fn_27_AFC48(int);
    virtual void slot3();
    virtual void slot4();
};

class soNullable {
public:
    virtual void isNull();
    virtual void fn_27_AFB14();
    virtual void fn_27_AFC14();
    virtual void fn_27_AFF70();
    virtual int fn_27_AFC68();

    char padding[12];
    ArrayObj array;

    int find(int id) {
        if (id <= -1)
            return -1;

        int count = fn_27_AFC68();
        for (int i = 0; i < count; ++i) {
            if (id == array.fn_27_AFC48(i).id)
                return i;
        }
        return -1;
    }
};

extern "C" int fn_27_AFC78(soNullable* self, int id) {
    int index = self->find(id);
    return (static_cast<unsigned int>(index) >> 31) ^ 1;
}
