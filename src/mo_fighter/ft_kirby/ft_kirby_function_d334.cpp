#pragma force_active on
extern "C" {

void fn_96_1DBE4(void*);
void fn_96_D7D0(void*, void*);
void fn_96_D874(void*, void*);
void fn_27_13604C(void*, void*, int, void*);

struct kirby_iface {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual int f9(int);
};

void fn_96_D334(void* self, void* a2, int a3, void* a4) {
    unsigned long base;
    char* data;
    void* p1;
    kirby_iface* iface;
    int result;

    base = reinterpret_cast<unsigned long>(self);
    base += 0x20000;
    base -= 0x48d4;
    data = reinterpret_cast<char*>(base);
    fn_96_1DBE4(data);

    p1 = *reinterpret_cast<void**>(reinterpret_cast<char*>(a4) + 0xD8);
    iface = *reinterpret_cast<kirby_iface**>(reinterpret_cast<char*>(p1) + 0x54);
    result = iface->f9(0);

    if (result == 0) {
        if ((reinterpret_cast<unsigned*>(a2)[0x1B] & 0x1F) != 7) {
            if (a3 != 0) {
                fn_96_D7D0(self, a4);
            } else {
                fn_96_D874(self, a4);
            }
        }
    }
    fn_27_13604C(self, a2, a3, a4);
}

}
