#pragma force_active on
struct Pair {
    float x, y;
};

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual unsigned long long slot9();
    virtual unsigned long long slot10();
    virtual unsigned long long slot11();
    virtual unsigned long long slot12();
};

struct Entry {
    void* a;
    void* b;
    void* c;
    void* d;
    bool hasFirstTwo() { return a && b; }
    bool valid() { return hasFirstTwo() && c; }
};

struct Context {
    char pad[0x60];
    Object_vptr_0* obj;
    char pad2[0x70];
    Entry entries[1];
};

extern "C" unsigned int fn_80134344(void*, int);
extern "C" void fn_80111E84(void*, void*, void*, void*);

extern "C" int fn_80135FA0(Context* self, int index, void* arg) {
    if (index == 0xff)
        return 0;

    bool valid2 = self->entries[index].valid();

    if (valid2 && fn_80134344(self, index) == 1) {
        Pair p;
        Pair out;
        Object_vptr_0* obj = self->obj;

        switch (index) {
        case 3: {
            unsigned long long temp = obj->slot9();
            p = *(Pair*)&temp;
            break;
        }
        case 0: {
            unsigned long long temp = obj->slot12();
            p = *(Pair*)&temp;
            break;
        }
        case 2: {
            unsigned long long temp = obj->slot11();
            p = *(Pair*)&temp;
            break;
        }
        case 1: {
            unsigned long long temp = obj->slot10();
            p = *(Pair*)&temp;
            break;
        }
        default:
            return 0;
        }

        fn_80111E84(&self->entries[index], &p, &out, arg);
        return 1;
    }

    return 0;
}
