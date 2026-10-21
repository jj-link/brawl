#pragma force_active on

extern "C" void* getInstance__9itManagerFv();
extern "C" int fn_27_23AC10(void*);
extern "C" void fn_27_23AC30(void*);
extern "C" void fn_800E1384(void*);
extern "C" void* g_IfMngr;

class Object {
    unsigned char padding[0x3C];

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
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual void slot21();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual int callback();

    unsigned char padding40[8];
    int index;
    unsigned char padding4C[0x14];
    int pending;
    unsigned char flag;
};

extern "C" void fn_27_23EEF4(Object* self) {
    if (getInstance__9itManagerFv() == 0) return;
    if (self->pending == 0) return;
    if (self->callback() == 0) return;
    if (fn_27_23AC10(self) == 0) return;

    if (self->flag == 1) {
        unsigned char* ifm = (unsigned char*)g_IfMngr;
        if (ifm != 0) {
            fn_800E1384(*(void**)(ifm + (self->index << 2) + 0x4C));
        }
    }

    fn_27_23AC30(self);
    self->pending = 0;
}
