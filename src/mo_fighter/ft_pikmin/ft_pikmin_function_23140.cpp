#pragma force_active on
extern "C" {
extern const char lbl_113_data_68B4[];
extern const char lbl_113_data_2950[];
void* __dynamic_cast(void*, int, const void*, const void*, short);
void* fn_113_183C0(void*);
int fn_27_BEB3C(void*, int);
int fn_27_7B610();
}

struct ObjA {
    virtual void v0();
    virtual void v1();
    virtual void* get(int);
};

struct ObjB {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual int v21();
};

struct Holder {
    void* ptr;
    bool flag;
};

struct Holder2 {
    void* ptr;
    bool flag;
    Holder2(const Holder& h) : ptr(h.ptr), flag(h.flag) {}
    const bool& isNull() const { return flag; }
    int get() const { return isNull() == 1 ? 0 : *(int*)((char*)ptr + 4); }
};

inline Holder makeHolder(void* p) {
    Holder h;
    h.ptr = p;
    h.flag = false;
    return h;
}

extern "C" int fn_113_23140(void*, int id, ObjA* obj, char* acc) {
    switch (id) {
    case 1000: {
        Holder2 h3(makeHolder(obj->get(0)));
        int v = h3.get();
        ObjB* b = *(ObjB**)(*(char**)(acc + 0xd8) + 8);
        int r;
        if (v != b->v21()) {
            r = v;
        } else {
            void* c = __dynamic_cast(*(void**)(acc + 8), 0x3c, lbl_113_data_68B4, lbl_113_data_2950, short(0));
            if (c == 0) {
                r = v;
            } else {
                r = fn_27_BEB3C(fn_113_183C0(c), 0);
            }
        }
        return r - v;
    }
    default:
        return fn_27_7B610();
    }
}
