#pragma force_active on
extern char lbl_27_data_316B8[];
extern char lbl_27_data_316C0[];

struct Vec3f {
    float x, y, z;

    Vec3f(const Vec3f& v) : x(v.x), y(v.y), z(v.z) {}
};

class Model {
    int pad[2];

public:
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2c();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3c();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4c();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5c();
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6c();
    virtual void v70();
    virtual void v74();
    virtual void v78();
    virtual void v7c();
    virtual void v80();
    virtual void v84();
    virtual int get88(const char*);
    virtual int get8c(int);
    virtual void v90();
    virtual void v94();
    virtual Vec3f get98(int, int);
};

class Position {
public:
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void set(const Vec3f&);
};

extern "C" void fn_27_18A744(void* a0, void* a1) {
    Model* o = *(Model**)((char*)*(void**)((char*)a1 + 0xd8) + 4);
    int r30 = o->get88(lbl_27_data_316B8);
    int r29 = o->get88(lbl_27_data_316C0);
    int r28 = o->get8c(0x12d);

    Vec3f s20 = o->get98(r30, 0);
    Vec3f s14 = o->get98(r29, 0);
    Vec3f s8 = o->get98(r28, 0);

    if (s20.y > s14.y) {
        if (s14.y < s8.y) {
            s8.y = s14.y;
        }
    } else if (s20.y < s8.y) {
        s8.y = s20.y;
    }

    Position* sub = *(Position**)((char*)*(void**)((char*)a1 + 0xd8) + 0xc);
    sub->set(s8);
}
