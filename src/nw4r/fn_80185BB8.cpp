#pragma force_active on
extern "C" {
void fn_80183374(void*, int, int, int);
}

class VirtObj {
public:
    virtual void v0() = 0;
    virtual void v1() = 0;
    virtual void v2() = 0;
    virtual void v3() = 0;
    virtual void v4() = 0;
    virtual void v5() = 0;
    virtual void v6() = 0;
    virtual void v7(int, int) = 0;
};

struct Elem {
    int pad;
    VirtObj* obj;
};

struct Container {
    unsigned char pad[0xFC];
    Elem* elems;
    unsigned char count;
};

extern "C" void fn_80185BB8(Container* self, int arg1, int arg2, int arg3) {
    for (int i = 0; i < (int)self->count; i++) {
        self->elems[i].obj->v7(arg1, arg2);
    }
    fn_80183374(self, arg1, arg2, arg3);
}
