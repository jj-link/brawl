#pragma force_active on
struct Dispatch {
    unsigned char pad[0x3c];
    virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3();
    virtual void f4(); virtual void f5(); virtual void f6(); virtual void f7();
    virtual void f8(); virtual void f9(); virtual void f10(); virtual void f11();
    virtual void f12(); virtual void f13(); virtual void f14(); virtual void f15();
    virtual void f16(); virtual void f17(); virtual void f18(); virtual void f19();
    virtual void f20(); virtual void f21(); virtual void f22(); virtual void f23();
    virtual void f24(); virtual void f25(); virtual void f26();
};
extern "C" void __ct__10grYakumonoFPCc(void*, const char*);
extern "C" const float lbl_77_rodata_28;
extern "C" unsigned char lbl_77_data_528[];
extern "C" Dispatch* fn_77_EF0(Dispatch* self, const char* name) {
    __ct__10grYakumonoFPCc(self, name);
    *(void**)((char*)self + 0x3c) = lbl_77_data_528;
    *((unsigned char*)self + 0x150) = 0;
    *(float*)((char*)self + 0x154) = lbl_77_rodata_28;
    self->f26();
    return self;
}
