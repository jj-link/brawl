#pragma force_active on
typedef unsigned int u32;

extern "C" {
extern void fn_8001B9EC(void *, int);
extern void fn_8001CFA4(void *);

struct Local {
    void *p;
    u32 f1;
    u32 f2;
    u32 f3;
    u32 f4;
    u32 f5;
};

void fn_8001D0C8(Local *arg0) {
    Local tmp;
    char buf[0x7C];

    tmp = *arg0;
    fn_8001B9EC(buf, (int)arg0->p);
    tmp.p = buf;
    fn_8001CFA4(&tmp);
}
}
