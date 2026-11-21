#include <so/so_array.h>
#include <new>
#pragma force_active on
#pragma use_simple_stdpnew on

extern "C" {
extern char lbl_27_data_1E938[], lbl_27_data_150C8[], lbl_27_data_1B58[];
extern char lbl_27_data_838DC[], lbl_27_data_12F08[];
extern signed char lbl_27_bss_526C;
extern void* lbl_27_bss_5270;
extern char lbl_27_bss_7B88[];

void fn_27_9FA44(void*);
void fn_27_9FA50(void*, int);
void fn_27_82C54(void*, int);
void __construct_array(void*, void (*)(void*), void (*)(void*, int), unsigned long, int);
void* __register_global_object(void*, void (*)(void*, int), void*);
void fn_27_9747C(void*, void*, void*, int, void*, void*, int, int, int, int, int, void*);
}

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual bool slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10(void*);
    virtual void slot11();
    virtual void slot12();
    virtual int slot13();
    virtual bool slot14();
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
    virtual void slot25();
    virtual void slot26();
    virtual int slot27();
    virtual int slot28();
    void* calc;
    unsigned int flags;
};

union Flags {
    unsigned int raw;
    struct {
        unsigned int pad : 4;
        unsigned int value : 2;
        unsigned int flag : 1;
        unsigned int rest : 25;
    } bits;
};

struct Arr {
    void* vt;
    void* calc;
    Flags flags;
};

struct Elem { signed char v; Elem() : v(-1) {} };
struct Vec1 {
    void* vt0;
    void* vt1;
    unsigned long top : 2;
    unsigned long last : 2;
    unsigned long size : 2;
    unsigned long isFull : 1;
    Elem elems[1];
    Vec1() : vt0(lbl_27_data_150C8), vt1(lbl_27_data_150C8 + 0x48), top(0), last(0), size(1), isFull(false) {}
};
struct Obj {
    Arr a;
    char elems[0x30];
    Vec1 b;
    Arr c;
    char padding[4];
    char rest[1];
};

static inline void fill(unsigned char* p, unsigned char* end) {
    while (p < end)
        *p++ = 0xff;
}

extern "C" Obj* fn_27_315934(
    Obj* self, void* arg1, int arg2, int arg3, int arg4, int arg5, int arg6
) {
    int n, i;

    self->a.vt = lbl_27_data_1E938;
    self->a.calc = lbl_27_data_1E938 + 0x48;
    self->a.flags.raw &= 0x0fffffff;
    self->a.flags.bits.value = 1;
    self->a.flags.bits.flag = 0;

    __construct_array(self->elems, fn_27_9FA44, fn_27_9FA50, 0x2c, 1);
    soArrayVectorCalculator::postInitialize(
        *(soArrayVectorCalcInterface*)&self->a.calc, 1, 1
    );

    new (&self->b) Vec1;

    soArrayVectorCalculator::postInitialize(
        *(soArrayVectorCalcInterface*)&self->b.vt1, 1, 1
    );

    Object_vptr_0* obj = (Object_vptr_0*)&self->c;
    *(void**)obj = lbl_27_data_1B58;
    obj->calc = lbl_27_data_1B58 + 0x48;
    obj->flags &= 0x01ffffff;

    n = soArrayVectorCalculator::resize(
        *(soArrayVectorCalcInterface*)&obj->calc, 1, obj->slot4(), obj->slot14(), obj->slot13(), obj->slot27(), obj->slot28()
    );

    for (i = 0; i < n; ++i)
        obj->slot10(lbl_27_data_838DC);

    if (!lbl_27_bss_526C) {
        lbl_27_bss_5270 = 0;
        lbl_27_bss_5270 = lbl_27_data_12F08;
        __register_global_object(
            &lbl_27_bss_5270, fn_27_82C54, lbl_27_bss_7B88
        );
        lbl_27_bss_526C = 1;
    }

    fn_27_9747C(
        self->rest, arg1, self, arg2, &self->c, &lbl_27_bss_5270,
        arg3, arg6, arg4, 5, arg5, &self->b
    );
    return self;
}
