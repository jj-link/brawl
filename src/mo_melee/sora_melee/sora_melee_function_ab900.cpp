#include <types.h>
#pragma force_active on
struct Data;
extern "C" void fn_27_7756C(void*, const void*);
extern "C" void* fn_27_ABB78(void*, int, u32, const s16*, int);
struct Data {
    char base[8];
    int id;
    s16 a;
    s16 priority;
    Data(const Data& x) {
        fn_27_7756C(this, &x);
        id = x.id;
        a = x.a;
        priority = x.priority;
    }
};
class soNullable {
public:
    virtual void isNull();
    virtual Data* slot1(int);
    virtual void slot2();
    virtual int slot3();
    virtual unsigned int slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10(Data*);
    virtual void slot11(int, Data*);
};
struct Short { s16 value; };
struct Outer {
    char pad[8];
    soNullable* list;
    inline int findPriority(int p) {
        if (p <= -1) return list->slot3();
        for (int i = 0; i < list->slot3(); i++) {
            int v = list->slot1(i)->priority;
            if (v <= -1) return i;
            if (v > p) return i;
        }
        return list->slot3();
    }
    inline int findId(int id) {
        for (int i = 0; i < list->slot3(); i++) {
            Data copy(*list->slot1(i));
            if (id == copy.id) return i;
        }
        return -1;
    }
};
extern "C" int fn_27_AB900(Outer* self, int arg1, int id, s16* arg3, int priority) {
    if (id > -1) {
        int i = self->findId(id);
        if (i >= 0) return -1;
    }
    if (id <= -1) id = -1;
    if (self->list->slot4() == 1U) {
        Short t = { *arg3 };
        char data[16];
        fn_27_ABB78(data, arg1, id, &t.value, priority);
        self->list->slot10((Data*)data);
        return id;
    }
    int index = self->list->slot3();
    if (priority >= 0) {
        index = self->findPriority(priority);
        if (index < 0) return -1;
    }
    Short t = { *arg3 };
    char data[16];
    fn_27_ABB78(data, arg1, id, &t.value, priority);
    self->list->slot11(index, (Data*)data);
    return id;
}