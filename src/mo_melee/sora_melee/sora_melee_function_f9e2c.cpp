#pragma force_active on
struct Entry {
    int unused;
    int id;
};
class Object_vptr_10 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual Entry& slot2(int);
};
class soNullable {
public:
    virtual void isNull();
    virtual void fn_27_F9CD8();
    virtual void fn_27_F9DD8();
    virtual void fn_27_FA124();
    virtual int fn_27_D9E04();

    char padding[12];
    Object_vptr_10 array;

    int find(int id) {
        if (id <= -1)
            return -1;
        int count = fn_27_D9E04();
        for (int i = 0; i < count; ++i) {
            if (id == array.slot2(i).id)
                return i;
        }
        return -1;
    }
};
extern "C" int fn_27_F9E2C(soNullable* self, int id) {
    int index = self->find(id);
    return (static_cast<unsigned int>(index) >> 31) ^ 1;
}