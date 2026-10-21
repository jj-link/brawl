#pragma force_active on

extern "C" {
extern unsigned char lbl_6_data_270[];
void fn_800FAEB8(void*, int);
void __dl__FPv(void*);
}

struct ChildBase {
    unsigned char pad[0x1D08];
};

struct Child : ChildBase {
    virtual ~Child();
};

struct Object {
    unsigned char pad0[0x3C];
    void* table;
    unsigned char pad1[0x16C];
    Child* child;
};

extern "C" void* fn_6_1E4(Object* self, int flag) {
    if (self) {
        self->table = lbl_6_data_270;
        delete self->child;

        if (self) {
            fn_800FAEB8(self, 0);
        }

        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
