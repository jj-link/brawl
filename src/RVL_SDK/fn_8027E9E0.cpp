#pragma force_active on

class Object {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2(int);
    int pad;
    int refcount;
};

extern "C" void fn_8027E9E0(Object* self) {
    if (--self->refcount == 0) {
        if (self) {
            self->slot2(1);
        }
    }
}
