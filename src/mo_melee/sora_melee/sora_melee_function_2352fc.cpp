#pragma force_active on

struct Pair { float x, y; };
struct Request { void* owner; unsigned short id; float x, y, z, a, b; unsigned int c, d; };

struct Class_4C3F4_base { unsigned int first; };
class Class_4C3F4 : public Class_4C3F4_base {
public:
    virtual void fn_27_234D84();
    virtual void fn_27_234C8C();
    virtual void fn_27_2350A4();
    virtual void fn_27_234D88(Request*);
    void* arg;
    unsigned char flag;
    char pad[0x2F];
    unsigned int result;
};

struct Param {
    char pad0[4];
    int type;
    char pad8[0x20];
    float pos_x;
    float pos_y;
    char pad30[4];
    float x;
    float y;
    float z;
    float a;
    float b;
    int c;
};

extern "C" {
extern char lbl_27_data_4C3C8[];
extern void* lbl_27_bss_5780;
void fn_27_234DDC(Class_4C3F4*, Param*, Pair*);
void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
void* fn_27_22A914(void*);
unsigned int fn_27_22ACB0(void*, Request*);
}

extern "C" Class_4C3F4* fn_27_2352FC(Class_4C3F4* self, void* arg, Param* p) {
    self->arg = arg;
    self->first = 0;
    self->flag = 0;
    *(void**)((char*)self + 4) = lbl_27_data_4C3C8;

    Pair copy;
    Pair tmp;
    tmp.y = p->pos_y;
    tmp.x = p->pos_x;
    p->type = 0x1A;
    ((unsigned int*)&copy)[0] = ((unsigned int*)&tmp)[0];
    ((unsigned int*)&copy)[1] = ((unsigned int*)&tmp)[1];
    fn_27_234DDC(self, p, &copy);

    Request req;
    req.id = 0xD;
    req.x = p->x;
    req.y = p->y;
    req.z = p->z;
    req.a = p->a;
    req.b = p->b;
    req.d = p->c;
    self->fn_27_234D88(&req);

    if (!lbl_27_bss_5780) {
        void* mgr = __nw__FUlQ25Heaps8HeapType(0x54, 2);
        if (mgr) mgr = fn_27_22A914(mgr);
        lbl_27_bss_5780 = mgr;
    }
    self->result = fn_27_22ACB0(lbl_27_bss_5780, &req);
    return self;
}