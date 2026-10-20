#pragma force_active on
struct Sec {
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
};

extern "C" {
void fn_27_1BBBD8(char* p) {
    Sec* s = (Sec*)(p + 0x10);
    s->b();
}
}
