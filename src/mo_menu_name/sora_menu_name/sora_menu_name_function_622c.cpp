#pragma force_active on
struct Raw {
    int w[16];
};

extern "C" {
extern void* g_gfPadSystem;
extern void* g_sndSystem;
extern void* g_gfHomeMenu;

void getSysPadStatus__11gfPadSystemFiP11gfPadStatus(void*, int, Raw*);
void playSE__9sndSystemF5SndIDiiii(void*, int, int, int, int, int);
void setBan__10gfHomeMenuFUlUl(void*, unsigned long, unsigned long);
}

inline Raw getRaw() {
    Raw s;
    getSysPadStatus__11gfPadSystemFiP11gfPadStatus(g_gfPadSystem, 0xf0, &s);
    return s;
}

struct Menu {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void remove(int);
    virtual void append(Menu*);

    char pad[0xe0];
    int count;

    void pop() {
        if (count != 0)
            remove(count - 1);
    }
};

extern "C" int fn_16_622C(char* self) {
    Raw status(getRaw());

    if (--*(int*)(self + 0x3f0) >= 0)
        return *(int*)(self + 0x9c);

    if (!(status.w[3] & 0x1100))
        return *(int*)(self + 0x9c);

    playSE__9sndSystemF5SndIDiiii(g_sndSystem, 1, -1, 0, 0, -1);
    setBan__10gfHomeMenuFUlUl(g_gfHomeMenu, 0, 3);

    Menu* menu = *(Menu**)(self + 0x94);
    while (menu->count != 0)
        menu->pop();

    Menu* obj = *(Menu**)(self + 0xa8);
    obj->append(*(Menu**)(self + 0x94));

    return 2;
}
