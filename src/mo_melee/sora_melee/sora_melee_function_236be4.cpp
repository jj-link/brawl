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

struct Prefix {
    int x;
};

struct Entry : Prefix {
    virtual void unused();
    virtual ~Entry();
};

struct Resource {
    char pad[0x10];
    void* value;
};

struct Object {
    Entry* entry;
    void* vtable;
    char pad[8];
    Resource* resource;
};

extern "C" Object* fn_27_236BE4(Object* self, int deleting) {
    if (self) {
        if (self) {
            self->vtable = lbl_27_data_4C3EC;
            if (self->resource) {
                if (!lbl_27_bss_5780) {
                    void* p = __nw__FUlQ25Heaps8HeapType(0x54, 2);
                    if (p) {
                        p = fn_27_22A914(p);
                    }
                    lbl_27_bss_5780 = p;
                }
                fn_27_22B194(lbl_27_bss_5780, self->resource->value);
                fn_80010E50(self->resource, 1);
            }
            self->resource = 0;
            if (self) {
                self->vtable = lbl_27_data_4BE88;
                Entry* p = self->entry;
                if (p) {
                    delete p;
                }
            }
        }
        if (deleting > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
