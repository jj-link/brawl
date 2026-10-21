#pragma force_active on

extern "C" const float lbl_100_rodata_28;

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
    virtual void send(int, Params*, int);
    virtual void v17();
    virtual void v18();
    virtual int get(int);
};

class WorkModule {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void setInt(int, unsigned int);
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

extern "C" void fn_100_DDB0(void*, Fighter* fighter) {
    Params p;
    p.kind = 11;
    p.flag = 0;
    p.a = -1;
    p.b = -1;
    p.c = -1;
    p.d = -1;
    p.value = lbl_100_rodata_28;
    p.enabled = 1;

    fighter->modules->article->send(0, &p, 0);

    WorkModule* work = fighter->modules->work;
    work->setInt(fighter->modules->article->get(0), 0x20000002);
    fighter->modules->work->setInt(p.b, 0x20000003);
    fighter->modules->work->setInt(p.c, 0x20000004);
}
