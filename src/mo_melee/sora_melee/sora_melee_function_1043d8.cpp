#include <types.h>
#pragma force_active on

struct Result {
    s32 a;
    s32 b;
    s16 c;
    s16 d;
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
    virtual Result* v26(s32 index);
};

extern "C" void fn_27_1043D8(MyClass* this_, s32 arg1, s32 arg2) {
    Result* r1 = this_->v26(arg1);
    Result* r2 = this_->v26(arg2);
    r2->a = r1->a;
    r2->b = r1->b;
    r2->c = r1->c;
    r2->d = r1->d;
}
