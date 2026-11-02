#pragma force_active on

struct Entry {
    int unused;
    int id;
};

class Class_18ED8 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual Entry* slot2(int);
    virtual void slot3();
    virtual void slot4();
};

class soNullable {
public:
    virtual void isNull();
    virtual void fn_27_1CBC00();
    virtual void fn_27_1CBD00();
    virtual void fn_27_1CC04C();
    virtual int fn_27_1B15F8();

    int padding[3];
    Class_18ED8 array;

    int find(int id) {
        if (id <= -1)
            return -1;

        int count = fn_27_1B15F8();
        for (int i = 0; i < count; ++i) {
            if (id == array.slot2(i)->id)
                return i;
        }
        return -1;
    }
};

extern "C" int fn_27_1CBD54(soNullable* self, int id) {
    int index = self->find(id);
    return (static_cast<unsigned int>(index) >> 31) ^ 1;
}
