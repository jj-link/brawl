#pragma force_active on
extern "C" void fn_27_34BB4C(void*);
extern "C" void* __dynamic_cast(void*, long, const void*, const void*, short);
extern "C" char lbl_27_data_8CB88[];
extern "C" char lbl_27_data_C938[];

class C00Base {
public:
    virtual ~C00Base();
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual int v5();
};

extern "C" int fn_27_346200(void*, C00Base* obj) {
    if (obj->v5() == 0xd) {
        void* p = __dynamic_cast(obj, 0, lbl_27_data_8CB88, lbl_27_data_C938, 0);
        if (!p) {
            return 0;
        }
        fn_27_34BB4C(p);
        return 0;
    }
    return 0;
}
