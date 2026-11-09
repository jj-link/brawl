#pragma force_active on

struct Entry {
    int unused;
    int id;
};

class Class_FB1F4 {
public:
    virtual void fn_27_FB1F4_0();
    virtual void fn_27_FB1F4_1();
    virtual Entry& fn_27_FB1F4_2(int);
    virtual void fn_27_FB1F4_3();
    virtual void fn_27_FB1F4_4();
};

class soNullable {
public:
    virtual void isNull();
    virtual void fn_27_FB0A0();
    virtual void fn_27_FB1A0();
    virtual void fn_27_FB4EC();
    virtual int fn_27_D9E24();

    char padding[12];
    Class_FB1F4 array;

    int find(int id) {
        if (id <= -1)
            return -1;

        int count = fn_27_D9E24();
        for (int i = 0; i < count; ++i) {
            if (id == array.fn_27_FB1F4_2(i).id)
                return i;
        }
        return -1;
    }
};

extern "C" int fn_27_FB1F4(soNullable* self, int id) {
    int index = self->find(id);
    return (static_cast<unsigned int>(index) >> 31) ^ 1;
}
