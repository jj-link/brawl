#pragma force_active on
extern "C" void* getNode__6utListFUl(void*, unsigned long);
extern "C" void* fn_27_6F30C(void*);

struct VT9 {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual int f9(int id);
};

struct VT19 {
    virtual void g0();
    virtual void g1();
    virtual void g2();
    virtual void g3();
    virtual void g4();
    virtual void g5();
    virtual void g6();
    virtual void g7();
    virtual void g8();
    virtual void g9();
    virtual void g10();
    virtual void g11();
    virtual void g12();
    virtual void g13();
    virtual void g14();
    virtual void g15();
    virtual void g16();
    virtual void g17();
    virtual void g18();
    virtual int g19();
};

extern "C" int fn_27_6C084(VT9* self) {
    if (self->f9(-1)) {
        unsigned char* node = (unsigned char*)getNode__6utListFUl((unsigned char*)self + 0x20, 0);
        while (node != 0) {
            unsigned char* elem = *(unsigned char**)(node + 0xc);
            if ((((unsigned long*)elem)[12] >> 8) & 8) {
                void* p = fn_27_6F30C(node);
                void* q = *(void**)((unsigned char*)p + 0x44);
                void* r = *(void**)((unsigned char*)q + 0xd8);
                void* s = *(void**)((unsigned char*)r + 0xac);
                return ((VT19*)s)->g19();
            }
            node = *(unsigned char**)node;
        }
    }
    return 0;
}
