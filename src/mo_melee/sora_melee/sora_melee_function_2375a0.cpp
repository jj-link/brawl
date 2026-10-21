#pragma force_active on

extern "C" {
void __dl__FPv(void*);
void* __dynamic_cast(void*, long, const void*, const void*, short);
extern char lbl_27_data_4BCC0[];
extern char lbl_27_data_4BCF8[];
extern char __RTTI__10gfCallBack[];
}

class Data {
public:
    void* m_ptr;
};

class Cb : public Data {
public:
    virtual void f0();
    virtual void f3(int);
};

extern "C" void* fn_27_2375A0(void* arg0, int arg1) {
    if (arg0) {
        if (arg0) {
            *reinterpret_cast<void**>(reinterpret_cast<char*>(arg0) + 4) = lbl_27_data_4BCC0;
            void* ptr = *reinterpret_cast<void**>(arg0);
            if (__dynamic_cast(ptr, 4, lbl_27_data_4BCF8, __RTTI__10gfCallBack, 0)) {
                Cb* cb = (Cb*)__dynamic_cast(*reinterpret_cast<void**>(arg0), 4, lbl_27_data_4BCF8, __RTTI__10gfCallBack, 0);
                if (cb) {
                    cb->f3(1);
                }
            }
        }
        if (arg1 > 0) {
            __dl__FPv(arg0);
        }
    }
    return arg0;
}
