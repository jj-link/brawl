#pragma force_active on
struct Elem {
    char pad[0xc];
    int field;
};

class Obj {
public:
    virtual void unused0();
    virtual void unused1();
    virtual void unused2(int, int);
    virtual void unused3();
    virtual void unused4();
};

extern "C" void fn_803340B8(Obj* self, Elem** a, int* b) {
    for (int i = 0; a[i] != 0 && b[i] != 0; i++) {
        if (a[i]->field != 0) {
            self->unused2(a[i]->field, b[i]);
        }
    }
}
