#pragma force_active on
extern "C" void __dl__FPv(void*);
extern "C" void* __dynamic_cast(void*, long, const void*, const void*, short);
extern "C" char lbl_27_data_4BCC0[];
extern "C" char lbl_27_data_4BCF8[];
extern "C" char __RTTI__10gfCallBack[];

struct Base4 {
    int unk0;
};

struct CallBackLike : Base4 {
    virtual void f0();
    virtual void f1(int);
    virtual void f2();
    virtual void f3();
};

extern "C" void* fn_27_2378D0(void* self, int flag) {
    if (self) {
        if (self) {
            *reinterpret_cast<void**>(static_cast<char*>(self) + 4) = lbl_27_data_4BCC0;
            if (__dynamic_cast(*reinterpret_cast<void**>(self), 4, lbl_27_data_4BCF8, __RTTI__10gfCallBack, 0)) {
                void* cb = __dynamic_cast(*reinterpret_cast<void**>(self), 4, lbl_27_data_4BCF8, __RTTI__10gfCallBack, 0);
                if (cb) {
                    reinterpret_cast<CallBackLike*>(cb)->f1(1);
                }
            }
        }
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
