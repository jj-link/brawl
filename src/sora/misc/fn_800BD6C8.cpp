#pragma force_active on
typedef unsigned int u32;
extern "C" {
int sprintf(char*, const char*, ...);
void Pushback__Q34nw4r3g3d6ScnMdlFPvPvPc(void*, void*, char*);
void fn_800B7AA4(void*, int, float);
extern char lbl_8059E0A0[8];
extern float lbl_805A2248;
extern float lbl_805A2264;

struct Obj {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void f(void*);
};
struct S {
    char pad0[0x130];
    void* a130[5];
    char pad1[0x964 - 0x144];
    char* a964[5];
    char pad2[0xb68 - 0x978];
    Obj* scn;
    char pad3[8];
    void* ab74[5];
    char pad4[0xe84 - 0xb88];
    char* e84;
    char pad5[0x12b8 - 0xe88];
    u32 a12b8[5];
};

void fn_800BD6C8(S* self, u32 idx, int mode) {
    char buf[8];
    sprintf(buf, lbl_8059E0A0, idx);
    if (mode == 0) return;
    switch (*(int*)(self->e84 + idx * 0x28 + 4)) {
    case 0:
        Pushback__Q34nw4r3g3d6ScnMdlFPvPvPc(self->scn, self->ab74[idx], buf);
        break;
    case 1:
        Pushback__Q34nw4r3g3d6ScnMdlFPvPvPc(self->scn, self->ab74[idx], buf);
        if (mode == 1) {
            fn_800B7AA4(self->a964[idx], 0x10, lbl_805A2264);
        } else {
            fn_800B7AA4(self->a964[idx], 0x10, lbl_805A2248);
        }
        break;
    case 2: case 3: case 4: case 5:
        Pushback__Q34nw4r3g3d6ScnMdlFPvPvPc(self->scn, *(void**)(self->a964[idx] + 0xc), buf);
        break;
    }
    S* p = self;
    for (int i = 0; i < 5; p = (S*)((char*)p + 4), i++) {
        if (idx == p->a12b8[0]) {
            if (mode == 1) {
                Pushback__Q34nw4r3g3d6ScnMdlFPvPvPc(self->scn, *(void**)((char*)self->a130[i] + 0xc), buf);
            } else {
                self->scn->f(*(void**)((char*)self->a130[i] + 0xc));
            }
            return;
        }
    }
}
}
