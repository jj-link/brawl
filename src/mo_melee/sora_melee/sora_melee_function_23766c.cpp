#pragma force_active on
typedef unsigned char u8;

extern "C" {
extern u8 lbl_27_data_4BCC0[];
extern u8 lbl_27_data_4BCF8[];
extern u8 __RTTI__10gfCallBack[];
void* __dynamic_cast(void*, long, const void*, const void*, short);
void __dl__FPv(void*);
}

struct Self {
    void* unk0;
    void* unk4;
};

struct CallBackObj {
    int pad;
    virtual void f0();
    virtual void f1(int);
    virtual void f2();
    virtual void f3();
};

extern "C" void* fn_27_23766C(Self* self, int deleting)
{
    if (self) {
        if (self) {
            self->unk4 = lbl_27_data_4BCC0;
            if (__dynamic_cast(self->unk0, 4, lbl_27_data_4BCF8, __RTTI__10gfCallBack, 0)) {
                CallBackObj* cb = (CallBackObj*)__dynamic_cast(self->unk0, 4, lbl_27_data_4BCF8, __RTTI__10gfCallBack, 0);
                if (cb) {
                    cb->f1(1);
                }
            }
        }
        if (deleting > 0) {
            __dl__FPv(self);
        }
    }

    return self;
}
