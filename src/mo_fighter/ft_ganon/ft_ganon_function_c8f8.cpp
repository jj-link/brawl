#pragma force_active on
extern "C" void fn_109_CA24(void*, int, int, int);
struct Event {
    int type;
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
    virtual void send(int, Event*, int);
    virtual void v17();
    virtual void v18();
    virtual int get(int);
};
class Class_71D8 {
public:
    virtual void fn_109_6868();
    virtual void fn_109_10E70();
    virtual void fn_109_119D4();
    virtual void fn_109_119CC();
    virtual void fn_109_119C4();
    virtual void fn_109_119BC(int, unsigned int);
    virtual void fn_109_119B4();
    virtual void fn_109_119AC();
    virtual void fn_109_119A4();
    virtual void fn_109_1199C();
    virtual void fn_109_11994();
    virtual void fn_109_1198C();
    virtual void fn_109_11984();
    virtual void fn_109_1197C();
    virtual void fn_109_1192C();
    virtual void fn_109_11974();
    virtual void fn_109_11964();
    virtual int fn_109_11954(unsigned int);
    virtual void fn_109_11944(unsigned int);
    virtual void fn_109_11934();
};
struct Modules {
    char pad[0x54];
    ArticleModule* article;
    char pad58[0xC];
    Class_71D8* work;
};
struct Fighter {
    char pad[0xD8];
    Modules* modules;
};
extern "C" void fn_109_C8F8(void*, Fighter* fighter) {
    Class_71D8* work = fighter->modules->work;
    if (work->fn_109_11954(0x22000015) == 0) {
        Event event;
        fn_109_CA24(&event, 0x21, 0x1b1, 1);
        fighter->modules->article->send(0, &event, 0);
        Modules* m = fighter->modules;
        Class_71D8* w = m->work;
        w->fn_109_119BC(m->article->get(0), 0x20000002);
        fighter->modules->work->fn_109_119BC(event.b, 0x20000003);
        fighter->modules->work->fn_109_119BC(event.c, 0x20000004);
        work->fn_109_11944(0x22000015);
    }
}