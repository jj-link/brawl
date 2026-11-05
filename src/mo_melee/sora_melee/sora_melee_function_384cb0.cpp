#pragma force_active on
extern "C" void* __dynamic_cast(void*, long, const void*, const void*, long);
extern "C" int fn_27_383CEC(void*, void*);
extern "C" char lbl_27_data_94D38[];
extern "C" char lbl_27_data_98E68[];
extern "C" char lbl_27_data_C938[];

class KindObj {
public:
    virtual ~KindObj();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual int getKind();
};

extern "C" int fn_27_384CB0(void*, void* arg, KindObj* obj) {
    switch (obj->getKind()) {
    case 0:
        return fn_27_383CEC(__dynamic_cast(obj, 0, lbl_27_data_98E68, lbl_27_data_C938, 1), arg);
    case 1:
        __dynamic_cast(obj, 0, lbl_27_data_94D38, lbl_27_data_C938, 1);
        return 1;
    case 2: return 1;
    case 3: return 1;
    case 4: return 1;
    case 5: return 1;
    case 6: return 1;
    case 7: return 1;
    case 8: return 1;
    case 9: return 1;
    case 10: return 1;
    case 11: return 1;
    case 12: return 1;
    case 13: return 1;
    case 14: return 1;
    case 15: return 1;
    case 16: return 1;
    default: return 0;
    }
}
