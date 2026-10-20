#pragma force_active on
extern "C" {
extern char lbl_27_data_907A8[];
extern char lbl_27_data_C938[];

void* __dynamic_cast(void*, long, const void*, const void*, short);
void fn_27_3635C4(void*);
}

struct Object {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual int getKind();
};

extern "C" int fn_27_36142C(void*, Object* object) {
    switch (object->getKind()) {
    case 13:
        fn_27_3635C4(__dynamic_cast(
            object, 0, lbl_27_data_907A8, lbl_27_data_C938, 0));
        return 0;
    default:
        return 0;
    }
}
