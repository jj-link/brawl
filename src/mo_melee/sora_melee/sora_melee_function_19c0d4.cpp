#pragma force_active on

class soArrayVectorCalcInterface;

class soArrayVectorCalculator {
public:
    int resize(soArrayVectorCalcInterface& iface, long a, bool b, bool c, long d, long e, long f);
};

struct VObj {
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual long v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12(int a);
    virtual void v13();
    virtual void v14();
    virtual bool v15();
    virtual bool v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual long v29();
    virtual long v30();
};

struct Outer {
    void* vt;
    soArrayVectorCalculator calc;
};

extern char lbl_27_data_38E60[];
extern "C" void fn_27_CCAC0(void*);
extern "C" void fn_27_4AD20(void*, short);
extern "C" void __construct_array(void*, void (*)(void*), void (*)(void*), unsigned long, int);

extern "C" void* fn_27_19C0D4(void* self, soArrayVectorCalcInterface* arg1, int arg2) {
    long extra;
    bool t40;
    bool t3c;
    long t74;
    long t78;
    long t18;
    unsigned flags = ((unsigned*)self)[2];
    ((void**)self)[0] = (void*)lbl_27_data_38E60;
    ((void**)self)[1] = (void*)(lbl_27_data_38E60 + 0x48);
    ((unsigned*)self)[2] = flags & 0x01FFFFFF;
    __construct_array((char*)self + 0xc, (void (*)(void*))fn_27_CCAC0, (void (*)(void*))fn_27_4AD20, 0x5c, 1);
    t78 = ((VObj*)self)->v30();
    t74 = ((VObj*)self)->v29();
    t3c = ((VObj*)self)->v15();
    t40 = ((VObj*)self)->v16();
    t18 = ((VObj*)self)->v6();
    int n = ((Outer*)self)->calc.resize(*arg1, t18, t40, t3c, t74, t78, extra);
    for (int i = 0; i < n; i++) {
        ((VObj*)self)->v12(arg2);
    }
    return self;
}
