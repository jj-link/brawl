#pragma force_active on

class IfSub {
public:
    virtual void v0();
    virtual void invoke(int a, int b, int c);
};

class IfMngrLike {
    unsigned char unused[0x14];

public:
    IfSub* sub;
};

extern IfMngrLike* g_IfMngr;

extern "C" void fn_800DD3BC() {
    IfSub* s = g_IfMngr->sub;
    if (s != 0) {
        s->invoke(8, 0, 0);
    }
}
