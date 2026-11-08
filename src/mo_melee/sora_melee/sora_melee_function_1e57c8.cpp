#pragma force_active on

struct Entry {
    int unused;
    int id;
};

class ArrayClass {
public:
    virtual void slot0();
    virtual void slot1();
    virtual Entry& slot2(int);
};

class soNullable {
public:
    virtual void isNull();
    virtual void fn_27_1E5664();
    virtual void fn_27_1E5764();
    virtual void fn_27_1E5AC0();
    virtual int fn_27_1E57B8();

    char padding[12];
    ArrayClass array;

    int find(int id) {
        if (id <= -1)
            return -1;
        int count = fn_27_1E57B8();
        for (int i = 0; i < count; ++i) {
            if (id == array.slot2(i).id)
                return i;
        }
        return -1;
    }
};

extern "C" int fn_27_1E57C8(soNullable* self, int id) {
    int index = self->find(id);
    return (static_cast<unsigned int>(index) >> 31) ^ 1;
}