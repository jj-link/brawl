#pragma force_active on

struct Pair { float x, y; };
struct Words { unsigned int x, y; };
struct Class_4C3F4_base { unsigned int first; };
class Class_4C3F4 : public Class_4C3F4_base {
public:
    virtual void fn_27_234D84();
    virtual void fn_27_234C8C();
    virtual void fn_27_2350A4();
    virtual void fn_27_234D88(struct Entry*);
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
    unsigned char flag;
    char pad2d[3];
    float y;
};
struct Entry {
    unsigned int unk0;
    unsigned short id;
    unsigned short pad6;
    float x;
    float y;
    unsigned char flag;
};
extern "C" {
extern char lbl_27_data_4C35C[];
extern const float lbl_27_rodata_38F0;
extern void* lbl_27_bss_5780;
void fn_27_234DDC(Class_4C3F4*, Param*, Pair*);
void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
void* fn_27_22A914(void*);
unsigned int fn_27_22AE84(void*, Entry*);
}
extern "C" Class_4C3F4* fn_27_236600(Class_4C3F4* self, void* arg, Param* p) {
    self->first = 0;
    self->flag = 0;
    self->arg = arg;
    *(void**)((char*)self + 4) = lbl_27_data_4C35C;
    p->type = 0x1C;
    Pair copy;
    Pair tmp;
    tmp.x = lbl_27_rodata_38F0;
    tmp.y = lbl_27_rodata_38F0;
    *(Words*)&copy = *(Words*)&tmp;
    fn_27_234DDC(self, p, &copy);
    Entry e;
    e.id = 0x11;
    e.x = p->x;
    e.flag = p->flag != 0;
    e.y = p->y;
    self->fn_27_234D88(&e);
    if (!lbl_27_bss_5780) {
        void* mgr = __nw__FUlQ25Heaps8HeapType(0x54, 2);
        if (mgr) {
            mgr = fn_27_22A914(mgr);
        }
        lbl_27_bss_5780 = mgr;
    }
    self->result = fn_27_22AE84(lbl_27_bss_5780, &e);
    return self;
}