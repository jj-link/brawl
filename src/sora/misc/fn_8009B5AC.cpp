#pragma force_active on
extern "C" void fn_80082544(int, int);
extern "C" void fn_8027EABC(void*, void*, unsigned int, int);
extern void* lbl_805A0EC8;

struct Timer {
    virtual void v2(int);
    unsigned short m4;
    short m6;
};
struct Vec {
    void* data;
    int size;
    unsigned int raw;
    bool isOwned() const { return (raw & 0x80000000) == 0; }
    void dealloc() { fn_8027EABC(lbl_805A0EC8, data, raw << 2, 0x15); }
    void clear() {
        if (isOwned()) dealloc();
        data = 0;
        size = 0;
        raw = (raw & 0x40000000) | 0x80000000;
    }
};
struct Obj {
    char pad[0x54];
    Timer* m54;
    int m58;
    unsigned char m5C;
    Vec v1;
    Vec v2;
    unsigned char m78;
    void update() {
        if (m5C != 0) {
            m78 = 1;
            if (v1.size == 0) v1.clear();
            if (v2.size == 0) v2.clear();
            if (m58 != 0 && v1.size == 0) {
                fn_80082544(m58, 1);
                m58 = 0;
            }
        } else {
            if (m78 != 0) {
                Timer* t = m54;
                if (t != 0) {
                    if (t->m4 != 0) {
                        t->m6 = t->m6 - 1;
                        if (t->m6 == 0 && t != 0) t->v2(1);
                    }
                    m54 = 0;
                }
                if (m58 != 0 && v1.size == 0) {
                    fn_80082544(m58, 1);
                    m58 = 0;
                }
                m78 = 0;
            }
        }
    }
};
extern "C" void fn_8009B334(Obj*);
extern "C" void fn_8009B5AC(Obj* self) {
    if (self->m5C != 0) {
        self->update();
        fn_8009B334(self);
        self->update();
    }
}