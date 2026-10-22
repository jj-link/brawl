#pragma force_active on
struct Obj {
    void* unk0;
    void* unk4;
};

struct Hdr {
    void* unk0;
};

class CallBack : public Hdr {
public:
    virtual void f0();
    virtual void f1(int);
};

extern "C" {
extern char lbl_27_data_4BCC0[];
extern char lbl_27_data_4BCF8[];
extern char __RTTI__10gfCallBack[];
void __dl__FPv(void*);
void* __dynamic_cast(void*, long, const void*, const void*, long);
}

extern "C" void* fn_27_237B34(Obj* self, int deleting)
{
    if (self) {
        if (self) {
            self->unk4 = lbl_27_data_4BCC0;
            if (__dynamic_cast(self->unk0, 4, lbl_27_data_4BCF8, __RTTI__10gfCallBack, 0)) {
                CallBack* cb = (CallBack*)__dynamic_cast(self->unk0, 4, lbl_27_data_4BCF8, __RTTI__10gfCallBack, 0);
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
