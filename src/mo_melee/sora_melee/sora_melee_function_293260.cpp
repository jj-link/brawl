#pragma force_active on

struct Entry {
    int unused0;
    int id;
};

class ArrayObj {
public:
    virtual void slot0();
    virtual void slot1();
    virtual Entry& getEntry(int index);
    virtual void slot3();
    virtual void slot4();
};

class soNullable {
public:
    virtual void isNull();
    virtual void fn_27_2930FC();
    virtual void fn_27_2931FC();
    virtual void fn_27_293558();
    virtual int fn_27_293250();

    char padding[12];
    ArrayObj array;

    int find(int id) {
        if (id <= -1)
            return -1;

        int count = fn_27_293250();
        for (int i = 0; i < count; ++i) {
            if (id == array.getEntry(i).id)
                return i;
        }
        return -1;
    }
};

extern "C" int fn_27_293260(soNullable* self, int id) {
    int index = self->find(id);
    return (static_cast<unsigned int>(index) >> 31) ^ 1;
}