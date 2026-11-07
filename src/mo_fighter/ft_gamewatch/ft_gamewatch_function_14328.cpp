#pragma force_active on
struct V { float x, y, z; };
struct Obj {
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual void s6();
    virtual void s7();
    virtual void s8();
    virtual void s9();
    virtual void s10();
    virtual void s11();
    virtual void s12();
    virtual void s13();
    virtual void s14();
    virtual void s15();
    virtual int getKind();
};
struct Pos {
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual V getPos();
    virtual void setPos(const V* in);
};
struct Acc {
    unsigned char pad[0xC];
    Pos* pos;
    unsigned char pad2[0x70 - 0x10];
    Obj* status;
};
struct Fighter {
    unsigned char pad[0xD8];
    Acc* acc;
};
extern "C" unsigned int fn_107_13FB4(void*, Fighter*, void*);
extern "C" float fn_107_14030(void*, Fighter*, void*);
extern float lbl_107_rodata_CC;

extern "C" void fn_107_14328(void* self, Fighter* f) {
    switch (f->acc->status->getKind()) {
    case 0x12f: case 0x130: case 0x131: case 0x132:
    case 0x133: case 0x134: case 0x135: case 0x136: {
        char buf[12];
        if (fn_107_13FB4(self, f, buf) == 1) {
            const V& v = f->acc->pos->getPos();
            float d = fn_107_14030(self, f, buf) - v.y;
            const_cast<V&>(v).y = v.y + lbl_107_rodata_CC * d;
            f->acc->pos->setPos(&v);
        }
    }
    }
}
