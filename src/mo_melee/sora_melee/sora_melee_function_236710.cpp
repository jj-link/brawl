#pragma force_active on

extern "C" {
extern unsigned char lbl_27_data_4C3EC[];
extern unsigned char lbl_27_data_4BE88[];
extern void* lbl_27_bss_5780;

void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
void* fn_27_22A914(void*);
void fn_27_22B194(void*, void*);
void fn_80010E50(void*, int);
void __dl__FPv(void*);
}

class Object {
    int field0;

public:
    virtual void dummy();
    virtual ~Object();
};

struct Resource {
    unsigned char pad[0x10];
    void* field10;
};

struct Wrapper {
    Object* field0;
    void* vtable;
    unsigned char pad[8];
    Resource* field10;
};

extern "C" Wrapper* fn_27_236710(Wrapper* self, int deleting) {
    if (self) {
        if (self) {
            self->vtable = lbl_27_data_4C3EC;
            if (self->field10) {
                if (!lbl_27_bss_5780) {
                    void* p = __nw__FUlQ25Heaps8HeapType(0x54, 2);
                    if (p) {
                        p = fn_27_22A914(p);
                    }
                    lbl_27_bss_5780 = p;
                }
                fn_27_22B194(lbl_27_bss_5780, self->field10->field10);
                fn_80010E50(self->field10, 1);
            }
            self->field10 = 0;
            if (self) {
                self->vtable = lbl_27_data_4BE88;
                Object* obj = self->field0;
                if (obj) {
                    delete obj;
                }
            }
        }
        if (deleting > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
