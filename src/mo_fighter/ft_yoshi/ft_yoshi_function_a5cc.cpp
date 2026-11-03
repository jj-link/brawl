#pragma force_active on
extern "C" {
extern signed char lbl_95_bss_32C;
extern char lbl_95_bss_330[8];
extern char lbl_95_bss_318[12];

void fn_27_3076D8(void*);
void* fn_27_3076E8(void*, int);
void* __register_global_object(void*, void*, void*);
void fn_27_307988(void*, void*, void*, unsigned int);
}

struct YoshiResourceModule {
    unsigned int pad0;
    unsigned int pad1;
    virtual void r00();
    virtual void r01();
    virtual void r02();
    virtual void r03();
    virtual void* getResourceIdAccesser();
};

struct YoshiResourceIdAccesser {
    virtual void i00();
    virtual void i01();
    virtual void i02();
    virtual void i03();
    virtual void i04();
    virtual void i05();
    virtual void i06();
    virtual void i07();
    virtual void i08();
    virtual void i09();
    virtual void i0A();
    virtual void i0B();
    virtual void i0C();
    virtual void i0D();
    virtual void i0E();
    virtual unsigned int getArchiveId();
};

extern "C" void fn_95_A5CC(void* a, void* b) {
    if (lbl_95_bss_32C == 0) {
        fn_27_3076D8(lbl_95_bss_330);
        __register_global_object(lbl_95_bss_330, (void*)fn_27_3076E8, lbl_95_bss_318);
        lbl_95_bss_32C = 1;
    }

    void* enumeration = *(void**)((char*)b + 0xD8);
    YoshiResourceModule* resource = (YoshiResourceModule*)*(void**)enumeration;
    YoshiResourceIdAccesser* ids = (YoshiResourceIdAccesser*)resource->getResourceIdAccesser();

    fn_27_307988(lbl_95_bss_330, a, b, ids->getArchiveId());
}
