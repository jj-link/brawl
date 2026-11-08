#pragma force_active on

struct Entry {
    int unused;
    int id;
};

class Class_26650 {
public:
    virtual void fn_27_10EB28();
    virtual void fn_27_10EAE0();
    virtual Entry& fn_27_10EB58(int);
    virtual void fn_27_10EB00();
    virtual void fn_27_10EB14();
};

class soNullable {
public:
    virtual void isNull();
    virtual void fn_27_1BBAD8();
    virtual void fn_27_1BBBD8();
    virtual void fn_27_1BBF24();
    virtual int fn_27_1B1458();

    char padding[12];
    Class_26650 array;

    int find(int id) {
        if (id <= -1)
            return -1;

        int count = fn_27_1B1458();
        for (int i = 0; i < count; ++i) {
            if (id == array.fn_27_10EB58(i).id)
                return i;
        }
        return -1;
    }
};

extern "C" int fn_27_1BBC2C(soNullable* self, int id) {
    int index = self->find(id);
    return (static_cast<unsigned int>(index) >> 31) ^ 1;
}
