#pragma force_active on

extern "C" void* getNode__6utListFUl(void*, unsigned long);
extern "C" void* fn_27_6F30C(void*);

struct Base {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual int v9(int);
};

struct Controller {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual int v9();
};

extern "C" int fn_27_6C1B4(Base* self) {
    if (self->v9(-1)) {
        unsigned char* node = (unsigned char*)getNode__6utListFUl(
            (unsigned char*)self + 0x20, 0);
        while (node != 0) {
            unsigned char* item = *(unsigned char**)(node + 0xc);
            if ((*(unsigned long*)(item + 0x30) >> 8) & 0x80) {
                unsigned char* p = *(unsigned char**)(
                    (unsigned char*)fn_27_6F30C(node) + 0x44);
                p = *(unsigned char**)(p + 0xd8);
                p = *(unsigned char**)(p + 0x58);
                return ((Controller*)p)->v9();
            }
            node = *(unsigned char**)node;
        }
    }
    return 1;
}
