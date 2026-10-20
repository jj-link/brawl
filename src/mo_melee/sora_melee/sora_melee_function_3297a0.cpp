#pragma force_active on
extern "C" void fn_27_32D704(int);
extern "C" void* __dynamic_cast(void*, long, const void*, const void*, short);
extern char lbl_27_data_87F80[];
extern char lbl_27_data_C938[];

class fnBaseObj {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual int getKind();
};

extern "C" {
int fn_27_3297A0(void*, fnBaseObj* obj) {
    int ret;
    switch (obj->getKind()) {
    case 0xd:
        fn_27_32D704((int)__dynamic_cast(obj, 0, lbl_27_data_87F80, lbl_27_data_C938, 0));
        ret = 0;
        break;
    default:
        ret = 0;
        break;
    }
    return ret;
}
}
