#pragma force_active on

extern "C" void fn_18_1C4C(void*, int);
extern char lbl_2_data_1C00[];

#define PTR(p, o) (*reinterpret_cast<void**>(reinterpret_cast<char*>(p) + (o)))
#define INT(p, o) (*reinterpret_cast<int*>(reinterpret_cast<char*>(p) + (o)))
#define U16(p, o) (*reinterpret_cast<unsigned short*>(reinterpret_cast<char*>(p) + (o)))

struct SceneBase {
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
    virtual void attach(void*, void*);
};

struct Scene : SceneBase {
    char pad4[0xE0];
    void* root;
};

struct Control {
    char pad[0x3C];
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
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual void f18();
    virtual void f19();
    virtual void f20();
    virtual void f21();
    virtual void f22();
    virtual void f23();
    virtual void f24();
    virtual void f25();
    virtual void f26();
    virtual void set(int, int);
};

extern "C" void fn_2_14114(void* self, Scene* a1, int mode) {
    unsigned int off;
    unsigned int i;

    PTR(self, 0x654) = a1;
    PTR(self, 0x63C) = lbl_2_data_1C00;
    INT(self, 0x644) = 0x24;
    i = 0;
    off = 0;

    do {
        void* p = PTR(reinterpret_cast<char*>(PTR(self, 0x64C)) + off, 0x90);
        a1->attach(a1->root, PTR(p, 0x10));
        i++;
        off += 4;
    } while (i < 3);

    switch (mode) {
    case 0:
        INT(self, 0x664) = 0;
        U16(self, 0x42) = 0;
        INT(self, 0x638) = 0;
        break;
    case 14:
        INT(self, 0x664) = 1;
        U16(self, 0x42) = 0;
        INT(self, 0x638) = 0xE;
        break;
    case 15:
        INT(self, 0x664) = 1;
        U16(self, 0x42) = 1;
        INT(self, 0x638) = 0xF;
        break;
    case 16:
        INT(self, 0x664) = 1;
        U16(self, 0x42) = 2;
        INT(self, 0x638) = 0x10;
        break;
    }

    fn_18_1C4C(self, 1);
    Control* obj = reinterpret_cast<Control*>(PTR(self, 0x658));
    obj->set(0xC, U16(self, 0x42) + 0x25);
}
