#pragma force_active on

struct Entry {
    int unused;
    int id;
};

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual Entry& slot2(int);
    virtual void slot3();
    virtual void slot4();
};

struct Object_vptr_10_base {
    char pad[0x10];
};

class Object_vptr_10 : public Object_vptr_10_base {
public:
    virtual void slot0();
    virtual void slot1();
    virtual Entry& slot2(int);
};

class soNullable {
public:
    virtual void isNull();
    virtual void fn_27_EFE98();
    virtual void fn_27_EFF98();
    virtual void fn_27_F02E4();
    virtual int fn_27_D9D04();

    char padding[12];
    Object_vptr_0 array;

    int find(int id) {
        if (id <= -1)
            return -1;

        int count = fn_27_D9D04();
        for (int i = 0; i < count; ++i) {
            if (id == array.slot2(i).id)
                return i;
        }
        return -1;
    }
};

extern "C" int fn_27_EFFEC(soNullable* self, int id) {
    int index = self->find(id);
    return (static_cast<unsigned int>(index) >> 31) ^ 1;
}
