#pragma force_active on
extern "C" void fn_8027EABC(void*, void*, unsigned int, int);
extern void* lbl_805A0EC8;

struct Vec {
    void* data;
    int size;
    unsigned int raw;

    bool isOwned() const {
        return (raw & 0x80000000) == 0;
    }

    void dealloc() {
        fn_8027EABC(lbl_805A0EC8, data, raw << 2, 0x15);
    }

    void clear() {
        if (isOwned())
            dealloc();
        data = 0;
        size = 0;
        raw = (raw & 0x40000000) | 0x80000000;
    }
};

class Counted {
public:
    virtual void slot0(int);
    unsigned short count;
    short refs;
};

struct Obj {
    int unk0;
    Counted* ptr;
    Vec v1;
    Vec v2;
    Vec v3;
};

extern "C" void fn_8008093C(Obj* self) {
    self->v1.clear();
    self->v2.clear();
    self->v3.clear();
    Counted* p = self->ptr;
    if (p->count != 0) {
        if (--p->refs == 0 && p != 0) {
            p->slot0(1);
        }
    }
}
