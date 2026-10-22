#pragma force_active on
#pragma use_lmw_stmw on
struct Alloc {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4();
    virtual void free(void*, unsigned short, int);
};
extern "C" void fn_802F0668(void*);
extern char lbl_804882A8[];
extern Alloc* lbl_805A0EB8;

struct Obj {
    char* vt;
    unsigned short m4;
    char* m8;
    char* mC;
    int pad;
    void* arr[6];
};

extern "C" {
Obj* fn_802E95E4(Obj* self, int flag) {
    if (self) {
        self->vt = lbl_804882A8;
        self->m8 = lbl_804882A8 + 0x10;
        self->mC = lbl_804882A8 + 0x20;
        for (int i = 0; i < 6; i++) {
            if (self->arr[i]) {
                fn_802F0668(self->arr[i]);
                self->arr[i] = 0;
            }
        }
        if (flag > 0) {
            lbl_805A0EB8->free(self, self->m4, 12);
        }
    }
    return self;
}
}
