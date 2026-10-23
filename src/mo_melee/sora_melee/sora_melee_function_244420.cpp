#pragma force_active on
extern "C" int fn_800EB300(const void* self);
extern "C" int fn_27_242B7C(void* self, int idx);
extern "C" int fn_27_23AC10(void* p);
extern "C" void fn_27_23CF9C(void* p);

struct Pad {
    unsigned char data[0x3C];
};

struct VObj : Pad {
    virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4(); virtual void s5(); virtual void s6(); virtual void s7(); virtual void s8(); virtual void s9();
    virtual void s10(); virtual void s11(); virtual void s12(); virtual void s13(); virtual void s14(); virtual void s15(); virtual void s16(); virtual void s17(); virtual void s18(); virtual void s19();
    virtual void s20(); virtual void s21(); virtual void s22(); virtual void s23();
    virtual void s24();
    virtual int s25();
    virtual unsigned int s26();
};

#define OBJ(self, off) (*(VObj**)((unsigned char*)(self) + (off)))

extern "C" void fn_27_244420(void* arg0) {
    unsigned char* self = (unsigned char*)arg0;

    if (self[0x40] == 0) goto end;
    if (self[0x1B5] == 1) goto end;
    if (OBJ(self, 0x1B8) != 0) {
        if (fn_800EB300(*(void**)((char*)OBJ(self, 0x1B8) + 0xCC)) == 0) goto end;
    }

    if (fn_27_242B7C(arg0, 0) != 0) {
        if (OBJ(self, 0x74)->s26() == 1U) goto end;
        if (OBJ(self, 0x74)->s25() == 0) goto end;
        if (fn_27_23AC10(OBJ(self, 0x74)) == 0) fn_27_23CF9C(OBJ(self, 0x74));
    }

    if (fn_27_242B7C(arg0, 1) != 0) {
        if (OBJ(self, 0x78)->s26() == 1U) goto end;
        if (OBJ(self, 0x78)->s25() == 0) goto end;
        if (fn_27_23AC10(OBJ(self, 0x78)) == 0) fn_27_23CF9C(OBJ(self, 0x78));
    }

    if (fn_27_242B7C(arg0, 2) != 0) {
        if (OBJ(self, 0x7C)->s26() == 1U) goto end;
        if (OBJ(self, 0x7C)->s25() == 0) goto end;
        if (fn_27_23AC10(OBJ(self, 0x7C)) == 0) fn_27_23CF9C(OBJ(self, 0x7C));
    }

    if (fn_27_242B7C(arg0, 3) != 0) {
        if (OBJ(self, 0x80)->s26() == 1U) goto end;
        if (OBJ(self, 0x80)->s25() == 0) goto end;
        if (fn_27_23AC10(OBJ(self, 0x80)) == 0) fn_27_23CF9C(OBJ(self, 0x80));
    }

    if (OBJ(self, 0x90) != 0) {
        OBJ(self, 0x90)->s24();
    }
    self[0x1B5] = 1;

end:
    return;
}
