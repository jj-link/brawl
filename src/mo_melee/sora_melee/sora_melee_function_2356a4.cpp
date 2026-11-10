#pragma force_active on

struct Pair { float x, y; };
struct Request { void* owner; unsigned short id; float x, y, z, a, b; unsigned int c, d; };

class Class_4C3A4_base { public: unsigned int first; };
class Class_4C3A4 : public Class_4C3A4_base {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void* slot2();
    virtual void slot3(Request*);
    void* arg;
    unsigned char flag;
    char pad[0x2F];
    unsigned int result;
};

struct Param {
    char pad0[4];
    int type;
    char pad8[0x20];
    float x;
    float y;
    char pad30[4];
    float z;
    unsigned char b38;
    char pad39[3];
    unsigned short trig;
    unsigned char b3e;
};

struct Obj1C { char pad[0x1c]; unsigned char b7 : 1; };
struct Blk { unsigned int u0; void* u4; unsigned int u8; unsigned char uC; void* u10; };
struct Blk2 { unsigned int u0; void* u4; unsigned int u8; bool uC; void* u10; };

extern "C" {
extern char lbl_27_data_4C3A4[];
extern char lbl_27_data_4C498[];
extern const float lbl_27_rodata_38F0;
extern const float lbl_27_rodata_390C;
extern void* lbl_27_bss_5780;
extern void* g_stTriggerMng;
void fn_27_234DDC(Class_4C3A4*, Param*, Pair*);
void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
void* fn_27_22A914(void*);
unsigned int fn_27_22ADDC(void*, Request*);
void* createTrigger__12stTriggerMngFQ27Gimmick8AreaKindP13stTriggerData(void*, int, void*);
void fn_27_233F58(void*, void*);
void fn_27_233FCC(void*, void*);
}

extern "C" Class_4C3A4* fn_27_2356A4(Class_4C3A4* self, void* arg, Param* p) {
    self->first = 0;
    self->arg = arg;
    self->flag = 0;
    *(void**)((char*)self + 4) = lbl_27_data_4C3A4;

    Pair copy;
    Pair tmp;
    tmp.y = p->y;
    tmp.x = p->x;
    p->type = 0x1B;
    ((unsigned int*)&copy)[0] = ((unsigned int*)&tmp)[0];
    ((unsigned int*)&copy)[1] = ((unsigned int*)&tmp)[1];
    fn_27_234DDC(self, p, &copy);

    if (p->trig != 0) {
        int var_r27;
        void* trig;
        void* cb;
        trig = createTrigger__12stTriggerMngFQ27Gimmick8AreaKindP13stTriggerData(g_stTriggerMng, 0, &p->trig);
        if (p->b3e & 1) {
            var_r27 = 1;
            Obj1C* t = (Obj1C*)self->slot2();
            t->b7 = 0;
        } else {
            var_r27 = 0;
        }
        cb = __nw__FUlQ25Heaps8HeapType(0x14, 0xF);
        if (cb != 0) {
            Blk* b = (Blk*)cb;
            void* v = self->slot2();
            b->u0 = 0;
            b->u8 = 0;
            b->u4 = lbl_27_data_4C498;
            b->uC = var_r27;
            b->u10 = v;
        }
        fn_27_233F58(trig, cb);
        cb = __nw__FUlQ25Heaps8HeapType(0x14, 0xF);
        if (cb != 0) {
            Blk2* b = (Blk2*)cb;
            void* v = self->slot2();
            b->u0 = 0;
            b->u8 = 0;
            b->u4 = lbl_27_data_4C498;
            b->uC = var_r27 == 0;
            b->u10 = v;
        }
        fn_27_233FCC(trig, cb);
    }

    Request req;
    req.id = 0xE;
    req.x = p->z;
    req.z = lbl_27_rodata_38F0;
    req.a = lbl_27_rodata_38F0;
    if (p->b38 != 0) {
        req.y = lbl_27_rodata_38F0;
    }
    if (p->b38 == 0) {
        req.y = lbl_27_rodata_390C;
    }
    req.d = 0;
    self->slot3(&req);

    if (lbl_27_bss_5780 == 0) {
        void* mgr = __nw__FUlQ25Heaps8HeapType(0x54, 2);
        if (mgr != 0) mgr = fn_27_22A914(mgr);
        lbl_27_bss_5780 = mgr;
    }
    self->result = fn_27_22ADDC(lbl_27_bss_5780, &req);
    return self;
}
