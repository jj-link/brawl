#pragma force_active on
struct Status {
    virtual void s08() = 0;
    virtual void s0c() = 0;
    virtual void s10() = 0;
    virtual void s14() = 0;
    virtual void s18() = 0;
    virtual void s1c() = 0;
    virtual void s20() = 0;
    virtual void s24() = 0;
    virtual void s28() = 0;
    virtual void s2c() = 0;
    virtual void s30() = 0;
    virtual void s34() = 0;
    virtual void s38() = 0;
    virtual void s3c() = 0;
    virtual void s40() = 0;
    virtual void s44() = 0;
    virtual int get() = 0;
};

struct Modules {
    char pad[0x70];
    Status* status;
};

struct Access {
    char pad[0xd8];
    Modules* modules;
};

extern "C" {
extern unsigned char lbl_109_bss_1B4[0x10];
void fn_109_D7DC(void*, Access*);

void fn_109_865C(void*, void*, Access* a) {
    switch (a->modules->status->get()) {
    case 0x115:
        fn_109_D7DC(lbl_109_bss_1B4, a);
        break;
    }
}
}
