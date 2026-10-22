#pragma force_active on
extern "C" {
extern const float lbl_27_rodata_9B8;
void fn_27_7021C(void* self, void* arg, float f);
void fn_27_714A4(short* out, void* src);
double fn_80400B3C(float x, double y);
}

struct Iface {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual int getCount();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void* getEntry(int);
};

struct Owner {
    char pad[0x20];
    Iface* iface;
};

extern "C" void fn_27_714B0(Owner* self, void* arg1, short* mask, float farg0, float farg1) {
    if (*mask != 0) {
        void* entry;
        int i;
        int count = self->iface->getCount();
        for (i = 0; i < count; i++) {
            entry = self->iface->getEntry(i);
            short sp8;
            fn_27_714A4(&sp8, entry);
            if (sp8 & *mask) {
                char* obj = *(char**)entry;
                float f = *(float*)(obj + 0x24);
                float v;
                if (f == farg0) {
                    v = lbl_27_rodata_9B8;
                } else if (f < farg0) {
                    v = farg0 - f;
                } else if (farg1 < lbl_27_rodata_9B8) {
                    v = lbl_27_rodata_9B8;
                } else if (f < farg1) {
                    v = (farg0 + farg1) - f;
                } else {
                    float r = (float)fn_80400B3C(f, farg1);
                    if (r < farg0) {
                        v = farg0 - r;
                    } else {
                        v = (farg0 + farg1) - r;
                    }
                }
                fn_27_7021C(obj, arg1, v);
            }
        }
    }
}
