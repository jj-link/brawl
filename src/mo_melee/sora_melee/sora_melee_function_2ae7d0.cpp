#pragma force_active on
class fn27Base {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual int v3();
};

extern "C" {
void* fn_27_2ACB8C(void* p, int x);
void fn_27_2ACE38(void* p, void* q);

void fn_27_2AE7D0(fn27Base* p) {
    int n = p->v3();
    void* q = fn_27_2ACB8C(p, n - 1);
    fn_27_2ACE38(p, q);
}
}
