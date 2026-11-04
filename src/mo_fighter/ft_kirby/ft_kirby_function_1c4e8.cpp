#pragma force_active on
#include <revolution/OS/OSError.h>

struct Accesser;

struct FighterBase {
    char pad[0x3c];
};

#define V(n) virtual void v##n();

class Fighter : public FighterBase {
public:
    V(0) V(1) V(2) V(3) V(4) V(5) V(6) V(7) V(8) V(9)
    V(10) V(11) V(12) V(13) V(14) V(15) V(16) V(17) V(18) V(19)
    V(20) V(21) V(22) V(23) V(24) V(25) V(26) V(27) V(28) V(29)
    V(30) V(31) V(32) V(33) V(34) V(35) V(36) V(37) V(38)
    virtual int v39();
    virtual int v40(Accesser*);
};

#undef V

class Controller {
public:
    virtual void c0();
    virtual void c1();
    virtual int c2();
    virtual void c3(int);
};

struct Modules {
    char pad[0xC0];
    Controller* ctrl;
};

struct Accesser {
    char pad0[8];
    void* object;
    char pad1[0xCC];
    Modules* modules;
};

struct Self {
    char pad[8];
    Accesser* accesser;
};

struct YBase {
    char pad[8];
};

class Y : public YBase {
public:
    virtual void y0();
    virtual void y1();
    virtual void y2();
    virtual void y3(int, int, void*, void*, void*);
};

struct Record {
    int a;
    int b;
    void* c;
};

struct Table {
    int pad;
    int count;
};

struct Data {
    int a;
    int b;
    int c;
    int d;
};

struct Weights {
    void* vtable;
    void* secondVtable;
    unsigned int count : 19;
    unsigned int flags : 13;
    float values[24];
};

struct Pair {
    int a;
    int b;
};

struct Ctx {
    Pair* pair;
    void* owner;
};

extern "C" {
extern char lbl_96_data_BBB4[];
extern char lbl_96_data_BD68[];
extern char lbl_96_data_608[];
extern char lbl_96_data_68D8[];
extern char g_ftCommonDataAccesser[];

void* __dynamic_cast(void*, long, const void*, const void*, short);
unsigned int fn_27_C37B4(void*);
void fn_27_C3488(void*, int, void*, void*);
unsigned char* fn_96_1D7B4(int);
Record* fn_96_1C78C(void*, int);
void fn_96_1C79C(void*, int, int, int, int, int);
int fn_96_1DD84(int);
void* fn_96_1E01C(void*, short);
void* fn_27_1E8374(int);
Data* fn_27_1458C8(void*, int);

void fn_96_1C4E8(Self* self, int id) {
    if (fn_27_C37B4((char*)self + 0xC) != 1U) {
        int r31;
        int r30;
        void* r29;
        OSReport(lbl_96_data_BBB4, id);
        Table* table = (Table*)fn_96_1D7B4(id);
        int i;
        for (i = 0; i < table->count; ++i) {
            r31 = fn_96_1C78C(table, i)->b;
            r30 = fn_96_1C78C(table, i)->a;
            r29 = fn_96_1C78C(table, i)->c;
            Weights weights;
            weights.vtable = lbl_96_data_BD68;
            weights.secondVtable = lbl_96_data_BD68 + 0x48;
            weights.count = 0;
            int r26 = self->accesser->modules->ctrl->c2();
            int r22 = *(int*)((char*)__dynamic_cast(self->accesser->object, 0x3c, lbl_96_data_608, lbl_96_data_68D8, (short)1) + 0x1C290);
            self->accesser->modules->ctrl->c3(r22);
            Controller* r21 = self->accesser->modules->ctrl;
            int r23 = ((Fighter*)self->accesser->object)->v40(self->accesser);
            int v41 = ((Fighter*)self->accesser->object)->v39();
            Ctx ctx;
            Pair pair;
            pair.a = v41;
            pair.b = r23;
            ctx.pair = &pair;
            ctx.owner = r21;
            ((Y*)fn_27_1E8374(r30))->y3(r31, r22, r29, &ctx, &weights);
            self->accesser->modules->ctrl->c3(r26);
            fn_27_C3488((void*)((int)self + 0xC), id, r29, &weights);
            fn_96_1E01C(&weights, (short)0);
        }
        if (fn_96_1DD84(id) > -1) {
            void* p = __dynamic_cast(self->accesser->object, 0x3c, lbl_96_data_608, lbl_96_data_68D8, (short)0);
            if (p != 0) {
                Data* d = fn_27_1458C8(g_ftCommonDataAccesser, id);
                if (d != 0) {
                    fn_96_1C79C(p, 0, 0, d->a, d->b, fn_96_1DD84(id));
                    fn_96_1C79C(p, 0, 1, d->c, d->d, fn_96_1DD84(id));
                }
            }
        }
    }
}
}
