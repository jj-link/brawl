#pragma force_active on

extern "C" {
void* fn_27_27A984(void*, int);
void __dl__FPv(void*);
extern unsigned char lbl_27_data_5A4D4[];
}

struct ResourceBase {
    unsigned char pad[0xA0];
};

struct Resource : ResourceBase {
    virtual ~Resource();
};

struct Object {
    unsigned char pad0[0x3C];
    void* vtable;
    unsigned char pad1[0x130];
    Resource* resource;
};

extern "C" void* fn_27_27AD60(Object* self, int flag) {
    if (self) {
        self->vtable = lbl_27_data_5A4D4;
        if (self->resource) {
            delete self->resource;
            self->resource = 0;
        }
        fn_27_27A984(self, 0);
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
