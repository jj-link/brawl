#pragma force_active on
typedef unsigned char u8;

extern "C" {
extern u8 lbl_27_data_4BCC0[];
extern u8 lbl_27_data_4BCF8[];
extern u8 __RTTI__10gfCallBack[];
void* __dynamic_cast(void*, long, const void*, const void*, short);
void __dl__FPv(void*);
}

class CallBack {
    void* m_next;
public:
    virtual void f0();
    virtual void proc(int);
};

extern "C" void* fn_27_23799C(void* self, int flag) {
    void* p = self;
    if (self) {
        if (p) {
            *reinterpret_cast<u8**>(static_cast<u8*>(self) + 4) = lbl_27_data_4BCC0;
            if (__dynamic_cast(*reinterpret_cast<void**>(self), 4, lbl_27_data_4BCF8, __RTTI__10gfCallBack, 0)) {
                CallBack* cb = static_cast<CallBack*>(
                    __dynamic_cast(*reinterpret_cast<void**>(self), 4,
                                  lbl_27_data_4BCF8, __RTTI__10gfCallBack, 0));
                if (cb) {
                    cb->proc(1);
                }
            }
        }
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
