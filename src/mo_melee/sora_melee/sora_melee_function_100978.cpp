#include <types.h>
#pragma force_active on

struct Result {
    int a;
    int b;
    short c;
    short d;
};

class MyClass {
public:
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual Result* v26(int index);
};

extern "C" void fn_27_100978(MyClass* self, int a, int b) {
    Result* p = self->v26(a);
    Result* q = self->v26(b);
    q->a = p->a;
    q->b = p->b;
    q->c = p->c;
    q->d = p->d;
}
