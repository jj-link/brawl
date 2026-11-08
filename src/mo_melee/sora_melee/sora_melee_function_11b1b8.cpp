#pragma force_active on

struct Entry {
    int unused0;
    int id;
};

class ArrayObj {
public:
    virtual void slot0();
    virtual void slot1();
    virtual Entry& fn_27_11B19C(int);
    virtual void slot3();
    virtual void slot4();
};

class soNullable {
public:
    virtual void isNull();
    virtual void fn_27_11B054();
    virtual void fn_27_11B154();
    virtual void fn_27_11B4B0();
    virtual int fn_27_11B1A8();

    char padding[12];
    ArrayObj array;

    int find(int id) {
        if (id <= -1)
            return -1;

        int count = fn_27_11B1A8();
        for (int i = 0; i < count; ++i) {
            if (id == array.fn_27_11B19C(i).id)
                return i;
        }
        return -1;
    }
};

extern "C" int fn_27_11B1B8(soNullable* self, int id) {
    int index = self->find(id);
    return (static_cast<unsigned int>(index) >> 31) ^ 1;
}
