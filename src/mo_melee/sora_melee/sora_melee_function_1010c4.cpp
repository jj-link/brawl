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
    virtual Result* v26(const Result* src);
};

extern "C" void fn_27_1010C4(MyClass* this_, const Result* a, const Result* b) {
    Result* r1 = this_->v26(a);
    Result* r2 = this_->v26(b);
    r2->a = r1->a;
    r2->b = r1->b;
    r2->c = r1->c;
    r2->d = r1->d;
}
