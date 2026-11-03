#pragma force_active on
struct Entry { int unused; int id; };
class Class_17F48 {
public:
    virtual void fn_27_C51D4();
    virtual void fn_27_C518C();
    virtual Entry& fn_27_C5AB4(int);
    virtual void fn_27_C51AC();
    virtual void fn_27_C51C0();
};
class soNullable {
public:
    virtual void isNull();
    virtual void fn_27_C49C8();
    virtual void fn_27_C4AC8();
    virtual void fn_27_C4E24();
    virtual int fn_27_C4B1C();
    char padding[12];
    Class_17F48 array;
    int find(int id) {
        if (id <= -1) return -1;
        int count = fn_27_C4B1C();
        for (int i = 0; i < count; ++i) {
            if (id == array.fn_27_C5AB4(i).id) return i;
        }
        return -1;
    }
};
extern "C" int fn_27_C4B2C(soNullable* self, int id) {
    return self->find(id) >= 0;
}