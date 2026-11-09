#pragma force_active on

struct Pair { void* first; void* second; };

class TargetObj {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void* v6(int);
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual Pair v13(short*);
};

struct Middle {
    char pad[0x7c];
    TargetObj* target;
};

struct Outer {
    char pad[0xd8];
    Middle* middle;
};

extern "C" Pair fn_27_164B10(void* arg0, void* arg1, unsigned int arg2) {
    short local = 1;
    Pair a;
    Pair b;
    Outer* outer = (Outer*)arg0;
    a = outer->middle->target->v13(&local);
    b = a;
    if (arg2 == 1) {
        outer->middle->target->v12();
    }
    void* p1 = outer->middle->target->v6(4);
    ((unsigned char*)p1)[5] |= 0x80;
    void* p2 = outer->middle->target->v6(6);
    ((unsigned char*)p2)[5] |= 0x80;
    return b;
}