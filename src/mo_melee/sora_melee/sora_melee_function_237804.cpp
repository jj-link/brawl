#pragma force_active on
extern "C" void __dl__FPv(void*);
extern "C" void* __dynamic_cast(void*, long, const void*, const void*, short);
extern "C" char lbl_27_data_4BCC0[];
extern "C" char lbl_27_data_4BCF8[];
extern "C" char __RTTI__10gfCallBack[];

struct Obj {
    void* unk0;
    void* unk4;
};

class CallBackPre {
public:
    int pad;
};

class CallBackX : public CallBackPre {
public:
    virtual void f0();
    virtual void f3(int);
};

extern "C" void* fn_27_237804(Obj* self, int arg)
{
    if (self) {
        if (self) {
            self->unk4 = lbl_27_data_4BCC0;
            if (__dynamic_cast(self->unk0, 4, lbl_27_data_4BCF8, __RTTI__10gfCallBack, 0)) {
                CallBackX* cb = (CallBackX*)__dynamic_cast(self->unk0, 4, lbl_27_data_4BCF8, __RTTI__10gfCallBack, 0);
                if (cb) {
                    cb->f3(1);
                }
            }
        }
        if (arg > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
