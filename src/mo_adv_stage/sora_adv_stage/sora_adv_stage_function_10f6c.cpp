#pragma force_active on
typedef unsigned char u8;

extern "C" {
extern u8 lbl_40_data_11A0[];
extern u8 lbl_40_data_11D8[];
extern u8 lbl_40_data_1610[];
void __dl__FPv(void*);
void* __dynamic_cast(void*, long, const void*, const void*, short);
}

struct Base {
    void* unk0;
};

struct Obj : Base {
    virtual void f0();
    virtual void f3(int);
};

extern "C" void* fn_40_10F6C(Base* self, int deleting) {
    if (self) {
        if (self) {
            *reinterpret_cast<void**>(reinterpret_cast<char*>(self) + 4) = lbl_40_data_11A0;
            if (__dynamic_cast(self->unk0, 4, lbl_40_data_11D8, lbl_40_data_1610, 0)) {
                Obj* r = reinterpret_cast<Obj*>(
                    __dynamic_cast(self->unk0, 4, lbl_40_data_11D8, lbl_40_data_1610, 0));
                if (r) {
                    r->f3(1);
                }
            }
        }
        if (deleting > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
