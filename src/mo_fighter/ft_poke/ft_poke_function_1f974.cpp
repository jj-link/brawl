#pragma force_active on
extern "C" void fn_27_368AAC(int a);
extern "C" void fn_27_560F0(int a);
extern "C" void fn_27_376A80(int a, int b, int c, int d);
extern "C" void fn_27_13138C(int a, int b, int c, int d, int e);

class Class_6EB8 {
public:
    virtual void fn_116_DEEC();
    virtual void fn_116_DD40();
    virtual void fn_116_DD48();
    virtual void fn_116_DD44();
    virtual void fn_116_DEE8();
    virtual void fn_116_DEE4();
    virtual void fn_116_DEE0();
    virtual void fn_116_DEDC();
    virtual void fn_116_DED8();
    virtual void fn_116_DED0();
    virtual void fn_116_DECC();
};

class Class_7624 {
public:
    virtual void fn_116_7384();
    virtual void fn_116_101BC();
    virtual Class_6EB8** fn_116_11518(int i);
    virtual void fn_116_11510();
    virtual int fn_116_11508();
    virtual void fn_116_11500();
    virtual void fn_116_114F8();
    virtual void fn_116_114F0();
    virtual void fn_116_114E8();
    virtual void fn_116_114E0();
    virtual void fn_116_114D8();
};

extern "C" Class_7624* fn_116_9570(int a);

extern "C" void fn_116_1F974(int arg0, int arg1, int arg2, int arg3, int arg4) {
    switch (arg1) {
    case 0x24:
    case 0x25:
    case 0x26:
    case 0x27:
    case 0x28:
    case 0x29:
    case 0x2a:
    case 0x2d:
    case 0x30:
    case 0x33:
    case 0x112:
    case 0x113:
    case 0x114:
        fn_27_368AAC(arg0 + 0x11118);
        if (arg1 == 0x112) {
            fn_27_560F0(arg0 + 0x11160);
        }
        break;
    case 0x119:
    {
        int i;
        Class_7624* mgr = fn_116_9570(arg0 + 0x11130);
        i = 0;
        while (i < mgr->fn_116_11508()) {
            Class_6EB8* p = *mgr->fn_116_11518(i);
            p->fn_116_DECC();
            i++;
        }
        break;
    }
    default:
        break;
    }
    fn_27_376A80(arg0 + 0x11130, arg1, arg2, arg3);
    fn_27_13138C(arg0, arg1, arg2, arg3, arg4);
}
