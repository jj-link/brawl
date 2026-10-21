#pragma force_active on

typedef unsigned char u8;

extern "C" {
extern u8 lbl_38_data_14[];
void __dt__6gfTaskFv(void*, int);
void __dl__FPv(void*);
}

struct NestedBase {
    u8 pad[0x5C];
};

struct Nested : NestedBase {
    virtual ~Nested();
};

struct fnObj {
    u8 pad[0x3C];
    void* vtable;
    u8 pad40[8];
    Nested* member48;
};

extern "C" fnObj* fn_38_D4(fnObj* self, int flag) {
    if (self) {
        self->vtable = lbl_38_data_14;
        if (self->member48) {
            delete self->member48;
            self->member48 = 0;
        }
        __dt__6gfTaskFv(self, 0);
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
