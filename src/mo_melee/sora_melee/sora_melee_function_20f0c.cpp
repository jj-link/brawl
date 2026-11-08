#pragma force_active on
extern "C" void* __dynamic_cast(void*, long, const void*, const void*, short);
extern "C" const char lbl_27_data_23C0[];
extern "C" const char lbl_27_data_2488[];
extern "C" const char lbl_27_data_2490[];

class Obj {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    int a;
    int b;
    int c;
};

struct Tmp {
    void* vt;
    int a;
    int b;
    int c;
};

extern "C" void fn_27_20F0C(void* self, int* src) {
    Obj* obj = (Obj*)__dynamic_cast(*(void**)self, 0, lbl_27_data_23C0, lbl_27_data_2488, 1);
    if (src == 0) {
        obj->slot8();
    } else {
        int s0 = src[0];
        int s1 = src[1];
        Tmp t;
        t.a = 0;
        t.vt = (void*)lbl_27_data_2490;
        t.b = s0;
        t.c = s1;
        if (s0 == 0) {
            t.c = 0;
        }
        if ((void*)obj != (void*)&t) {
            if (&obj->a != &t.a) {
                obj->a = t.a;
            }
            int bv = t.b;
            obj->b = bv;
            obj->c = t.c;
            if (bv == 0) {
                obj->c = 0;
            }
        }
    }
}
