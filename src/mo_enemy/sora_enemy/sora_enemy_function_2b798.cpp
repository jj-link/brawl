#pragma force_active on
extern "C" {
extern char __RTTI__5Enemy[];
extern char __RTTI__11StageObject[];
void* __dynamic_cast(void*, long, const void*, const void*, short);
}

struct V3 {
    float x, y, z;
};

extern "C" V3 fn_41_6270(void*, int);

class VObj {
public:
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual void s6();
    virtual void s7();
    virtual void s8();
    virtual void s9();
    virtual void s10();
    virtual void s11();
    virtual void s12();
    virtual void s13();
    virtual void s14();
    virtual void s15();
    virtual void s16();
    virtual int s17(int);
    virtual void s18();
};

struct Handler {
    float run();
};

inline float Handler::run() {
    char* self = (char*)this;
    void* enemy;
    VObj* m;
    char* p = *(char**)(self + 0x54);
    m = *(VObj**)(*(char**)(p + 0xd8) + 0xc);
    enemy = __dynamic_cast(
        *(void**)(p + 8), 0x3C,
        __RTTI__5Enemy, __RTTI__11StageObject, 1);
    VObj* w = *(VObj**)(*(char**)(*(char**)(self + 0x54) + 0xd8) + 0x64);
    int id = w->s17(0x12000003);
    m->s18();
    return fn_41_6270(enemy, id).y;
}

extern "C" float fn_41_2B798(Handler* self) {
    return self->run();
}
