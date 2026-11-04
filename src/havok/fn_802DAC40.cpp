#pragma force_active on
#pragma use_lmw_stmw on
extern "C" void fn_8027EABC(void*, void*, unsigned int, int);
extern char lbl_80487A38[];
extern void* lbl_805A0EC8;
class SoHeapAllocator {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void free(void*, unsigned short, int);
};
extern SoHeapAllocator* lbl_805A0EB8;
class Elem {
public:
    virtual void vf0(int);
    unsigned short m04;
    short m06;
};
struct Entry {
    char pad[0x40];
    Elem* e[3];
    char pad2[4];
};
struct Array {
    Entry* data;
    int count;
    unsigned int raw;
    bool isOwned() const { return (raw & 0x80000000) == 0; }
    void dealloc() { fn_8027EABC(lbl_805A0EC8, data, (raw & 0x3fffffff) * 0x50, 0x15); }
};
struct Obj {
    void* vtable;
    unsigned short type;
    char pad[0x12];
    Array array;
};
extern "C" Obj* fn_802DAC40(Obj* self, int flag) {
    if (self) {
        self->vtable = lbl_80487A38;
        for (int i = 0; i < self->array.count; i++) {
            for (int j = 0; j < 3; j++) {
                Elem* e = self->array.data[i].e[j];
                if (e && e->m04 != 0) {
                    if (--e->m06 == 0 && e != 0) {
                        e->vf0(1);
                    }
                }
            }
        }
        if ((char*)&self->array != 0 && self->array.isOwned())
            self->array.dealloc();
        if (flag > 0)
            lbl_805A0EB8->free(self, self->type, 0x2a);
    }
    return self;
}