#pragma force_active on

class Obj {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
};

struct Entry {
    int a;
    int b;
    Obj* obj;
};

class Self {
public:
    virtual void destroy(int flag);
    char pad[8];
    Entry* entries;
    unsigned int count;
};

extern "C" void fn_802A3E74(Self* self) {
    Entry* e = self->entries;
    Entry* end = e + self->count;
    for (; e != end; e++) {
        if (e->obj != 0) {
            e->obj->v6();
        }
    }
    if (self != 0) {
        self->destroy(1);
    }
}
