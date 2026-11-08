#pragma force_active on
extern "C" void fn_93_10090(void* obj);
extern "C" int fn_93_102D0(void* self);
extern "C" void fn_93_10BA0(void* self, struct Vec3f* p, struct Vec3f* q);
extern const float lbl_93_rodata_6C;

struct Vec3f {
    float x, y, z;
};

struct State {
    int a;
    int b;
    int mode;
    int id;
    Vec3f out;
};

struct Local {
    int a;
    int b;
    Vec3f p;
    Vec3f q;
};

class ClsA {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual int v9();
};

class ClsWork {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual int getInt(int);
    virtual void setInt(int, int);
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void onFlag(int);
};

class ClsB {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void sendEventNodes(int, void*, int);
};

class ClsC {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void changeStatus(int, void*);
};

class ClsD {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void clearSpeedAll();
};

class ClsE {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual int effect(unsigned int, int, Vec3f*, Vec3f*, float, int, int, int);
};

struct Modules {
    char p00[0x44];
    ClsA* a44;
    char p48[0xC];
    ClsB* b54;
    char p58[0xC];
    ClsWork* w64;
    char p68[0x8];
    ClsC* c70;
    char p74[0x8];
    ClsD* d7c;
    char p80[0x8];
    ClsE* e88;
};

extern "C" void fn_93_10140(void* arg1, void* self) {
    ClsWork* w31 = (*reinterpret_cast<Modules**>(reinterpret_cast<char*>(self) + 0xd8))->w64;
    if ((*reinterpret_cast<Modules**>(reinterpret_cast<char*>(self) + 0xd8))->a44->v9() == 0) {
        State st;
        fn_93_10090(&st);
        st.mode = 2;
        (*reinterpret_cast<Modules**>(reinterpret_cast<char*>(self) + 0xd8))->b54->sendEventNodes(0, &st, 0);
        w31->onFlag(0x22000011);
        ClsWork* w30 = (*reinterpret_cast<Modules**>(reinterpret_cast<char*>(self) + 0xd8))->w64;
        if (w30->getInt(0x20000001) == 0) {
            ClsE* effect = (*reinterpret_cast<Modules**>(reinterpret_cast<char*>(self) + 0xd8))->e88;
            Local loc;
            fn_93_10BA0(self, &loc.p, &loc.q);
            loc.a = -1;
            int r = effect->effect(0xE20002, 0, &loc.p, &loc.q, lbl_93_rodata_6C, 1, 0, 0);
            w30->setInt(r, 0x20000001);
        }
        if (fn_93_102D0(self) != 0) {
            (*reinterpret_cast<Modules**>(reinterpret_cast<char*>(self) + 0xd8))->c70->changeStatus(0x11B, self);
            (*reinterpret_cast<Modules**>(reinterpret_cast<char*>(self) + 0xd8))->d7c->clearSpeedAll();
        }
    }
}
