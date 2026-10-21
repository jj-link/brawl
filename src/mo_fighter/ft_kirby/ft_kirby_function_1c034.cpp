#pragma force_active on
typedef unsigned int u32;

#define V8(p) \
    virtual void p##0(); \
    virtual void p##1(); \
    virtual void p##2(); \
    virtual void p##3(); \
    virtual void p##4(); \
    virtual void p##5(); \
    virtual void p##6(); \
    virtual void p##7();

#define V32(p) V8(p##a) V8(p##b) V8(p##c) V8(p##d)

struct ObjectBase {
    char pad[0x3c];
};

struct Object : ObjectBase {
    V32(a) V32(b) V32(c) V32(d)
    V8(e) V8(f)
    virtual void h0();
    virtual int test();
    virtual void h2();
    virtual void h3();
    virtual void end();
};

#undef V32
#undef V8

extern "C" {
void* getInstance__15gfTaskSchedulerFv();
void* getTask__15gfTaskSchedulerFQ26gfTask8CategoryUl(void*, int, u32);
void* __dynamic_cast(void*, long, const void*, const void*, short);

extern char lbl_96_data_5DA8[];
extern char lbl_96_data_69D8[];

void fn_96_1C034() {
    u32 i = 0;
    void* task = getTask__15gfTaskSchedulerFQ26gfTask8CategoryUl(
        getInstance__15gfTaskSchedulerFv(), 12, 0);

    while (task) {
        Object* object = (Object*)__dynamic_cast(
            task, 0x3c, lbl_96_data_5DA8, lbl_96_data_69D8, 0);
        if (object) {
            if (object->test()) {
                object->end();
            } else {
                ++i;
            }
        } else {
            ++i;
        }

        task = getTask__15gfTaskSchedulerFQ26gfTask8CategoryUl(
            getInstance__15gfTaskSchedulerFv(), 12, i);
    }
}
}
