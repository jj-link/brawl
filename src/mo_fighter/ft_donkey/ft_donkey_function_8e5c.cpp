#pragma force_active on

struct Blob {
    void* vptr;
};

struct Dispatch {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3(void*);
};

extern "C" {
extern signed char lbl_92_bss_1AC;
extern Blob lbl_92_bss_1B0;
extern char lbl_92_bss_198[];
void fn_27_12DCA8(void*);
void fn_27_2DE170(void*);
void* fn_27_2DE180(void*, int);
void* __register_global_object(void* object, void* destructor, void* chain);
}

extern "C" void fn_92_8E5C(void* obj) {
    fn_27_12DCA8(obj);
    if (lbl_92_bss_1AC == 0) {
        fn_27_2DE170(&lbl_92_bss_1B0);
        __register_global_object(&lbl_92_bss_1B0, (void*)fn_27_2DE180, &lbl_92_bss_198);
        lbl_92_bss_1AC = 1;
    }
    reinterpret_cast<Dispatch*>(&lbl_92_bss_1B0)
        ->v3(*reinterpret_cast<void**>(reinterpret_cast<char*>(obj) + 0x60));
}
