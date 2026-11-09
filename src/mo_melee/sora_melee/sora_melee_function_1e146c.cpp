#pragma force_active on

extern "C" {
extern signed char lbl_27_bss_5210;
extern char lbl_27_data_11498[];
extern char lbl_27_bss_51B8[];

void fn_27_82714(void*, int);
void __register_global_object(void*, void*, void*);
void fn_27_2520C(void*, void*, void*, void*);
}

struct GlobalObject { void* vtable; };
extern GlobalObject lbl_27_bss_5214;

static inline GlobalObject* getGlobal() {
    if (lbl_27_bss_5210 == 0) {
        lbl_27_bss_5214.vtable = 0;
        lbl_27_bss_5214.vtable = &lbl_27_data_11498;
        __register_global_object(&lbl_27_bss_5214, (void*)fn_27_82714, lbl_27_bss_51B8);
        lbl_27_bss_5210 = 1;
    }
    return &lbl_27_bss_5214;
}

struct Sub {
    virtual void fn_27_7B274();
    virtual void fn_27_7AC18();
    virtual void fn_27_7AC28();
    virtual void fn_27_C4474();
    virtual void fn_27_7B2EC();
    virtual void fn_27_C4434();
    virtual void fn_27_7AD2C();
    virtual void fn_27_7AEDC();
    virtual void fn_27_7B22C();
    virtual void fn_27_7AC38();
    virtual void fn_27_7ADE8();
    virtual void fn_27_7AF98();
    virtual void fn_27_7B0B0();
};

struct Outer {
    void* unk0;
    Sub sub;
};

extern "C" void* fn_27_1E146C(Outer* obj, void* arg1, void* arg2) {
    fn_27_2520C(&obj->sub, arg1, getGlobal(), arg2);
    obj->sub.fn_27_7B0B0();
    return obj;
}
