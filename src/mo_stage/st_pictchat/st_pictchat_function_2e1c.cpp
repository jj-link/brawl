#pragma force_active on
extern "C" {
extern unsigned char lbl_73_data_C20[];
void __dt__10grYakumonoFv(void*, int);
void __dl__FPv(void*);
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
    unsigned char pad1[0x118];
    Resource* resource;
};

extern "C" void* fn_73_2E1C(Object* self, int flag) {
    if (self) {
        self->vtable = lbl_73_data_C20;
        if (self->resource) {
            delete self->resource;
            self->resource = 0;
        }
        if (self) {
            __dt__10grYakumonoFv(self, 0);
        }
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
