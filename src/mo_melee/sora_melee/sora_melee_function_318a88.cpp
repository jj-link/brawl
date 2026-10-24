#pragma force_active on
extern "C" void* __dynamic_cast(void*, long, const void*, const void*, short);
extern "C" char lbl_27_data_84F08[];
extern "C" char lbl_27_data_C938[];

class Object {
public:
    virtual ~Object();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual int getKind();
};

extern "C" int fn_27_318A88(void*, void*, Object* obj) {
    switch (obj->getKind()) {
    case 0:
        __dynamic_cast(obj, 0, lbl_27_data_84F08, lbl_27_data_C938, 1);
        return 1;
    case 1: return 1;
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
