#pragma force_active on
extern "C" {
extern signed char lbl_107_bss_144;
extern char lbl_107_bss_148[8];
extern char lbl_107_bss_130[12];

void fn_27_34E3B8(void*);
void* fn_27_34E3C8(void*, int);
void* __register_global_object(void*, void*, void*);
void fn_27_34E608(void*, void*, void*, unsigned int);
}

struct GameWatchResourceModule {
    unsigned int pad0;
    unsigned int pad1;
    virtual void reserved00();
    virtual void reserved01();
    virtual void reserved02();
    virtual void reserved03();
    virtual void* getResourceIdAccesser();
};

struct GameWatchResourceIdAccesser {
    virtual void reserved00();
    virtual void reserved01();
    virtual void reserved02();
    virtual void reserved03();
    virtual void reserved04();
    virtual void reserved05();
    virtual void reserved06();
    virtual void reserved07();
    virtual void reserved08();
    virtual void reserved09();
    virtual unsigned int getArchiveId();
};

extern "C" void fn_107_B64C(void* weapon, void* accesser) {
    if (lbl_107_bss_144 == 0) {
        fn_27_34E3B8(lbl_107_bss_148);
        __register_global_object(lbl_107_bss_148,
                                 (void*)fn_27_34E3C8,
                                 lbl_107_bss_130);
        lbl_107_bss_144 = 1;
    }

    void* enumeration = *(void**)((char*)accesser + 0xD8);
    GameWatchResourceModule* resource =
        (GameWatchResourceModule*)*(void**)enumeration;
    GameWatchResourceIdAccesser* ids =
        (GameWatchResourceIdAccesser*)resource->getResourceIdAccesser();

    fn_27_34E608(lbl_107_bss_148, weapon, accesser, ids->getArchiveId());
}
