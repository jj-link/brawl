#pragma force_active on
class fnObj {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual fnObj* v8(int);
    unsigned char m4;
    unsigned char m5;
};

class fnMid {
public:
    unsigned char pad[0x7c];
    fnObj* obj;
};

class fnOwner {
public:
    unsigned char pad[0xd8];
    fnMid* mid;
};

extern "C" void fn_27_3A1FF4(void* unused, fnOwner* owner) {
    fnObj* b = owner->mid->obj->v8(0);
    b->m5 |= 0x80;
}
