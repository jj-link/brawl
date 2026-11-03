#pragma force_active on

extern "C" const float lbl_118_rodata_28;

struct Params {
    int kind;
    unsigned char flag;
    int a;
    int b;
    int c;
    int d;
    float value;
    unsigned char enabled;
};

class ArticleModule {
public:
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
    virtual void v16();
    virtual void v17();
    virtual void send(int, Params*, int);
    virtual void v19();
    virtual void v20();
    virtual int get(int);
};

class WorkModule {
public:
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void setInt(int, unsigned int);
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void setFloat(float, unsigned int);
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual int getInt(unsigned int);
    virtual void reset(unsigned int);
};

struct Modules {
    char pad[0x54];
    ArticleModule* article;
    char pad58[0xC];
    WorkModule* work;
};

struct Fighter {
    char pad[0xD8];
    Modules* modules;
};

extern "C" void fn_118_D790(void*, Fighter* fighter) {
    WorkModule* work = fighter->modules->work;
    int idA = work->getInt(0x22000011);
    int idB = work->getInt(0x22000010);
    if (idA == 0 && idB != 0) {
        Params p;
        p.kind = 11;
        p.flag = 0;
        p.a = 0x77;
        p.b = -1;
        p.c = -1;
        p.d = -1;
        p.value = lbl_118_rodata_28;
        p.enabled = 1;

        fighter->modules->article->send(0, &p, 0);
        Modules* m = fighter->modules;
        WorkModule* w = m->work;
        w->setInt(m->article->get(0), 0x20000002);
        fighter->modules->work->setInt(p.b, 0x20000003);
        fighter->modules->work->setInt(p.c, 0x20000004);
        fighter->modules->work->setFloat(p.value, 0x21000004);
        work->reset(0x22000011);
    }
}
