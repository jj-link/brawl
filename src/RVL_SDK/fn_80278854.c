#pragma force_active on

typedef struct {
    char pad0[0x8];
    int field8;
    char padC[0x5C4];
    void* field5D0;
    char pad5D4[0xC];
    void* field5E0;
    void* field5E4;
} Obj;

extern void* fn_80204E5C(void*, int);
extern void* fn_801C8754(void*);
extern unsigned long fn_801C8D38(void*, void*);
extern unsigned long fn_801C8E68(void*, void*);
extern int fn_801C8B3C(void*, void*, void*, unsigned long, void*, unsigned long);
extern void* fn_801CA838(void*);
extern void fn_801CA8F0(void*, void*, int);
extern void fn_801CA274(void*, int, void*, int);
extern int lbl_80532160[4];

void fn_80278854(Obj* self, void* arg1, int arg2) {
    void* buffer1;
    void* p;
    void* q;
    void* b1;
    void* b3;
    unsigned long size1;
    unsigned long size2;
    int v;
    buffer1 = fn_80204E5C(lbl_80532160, 0xE0);
    if (buffer1) {
        if (buffer1) buffer1 = fn_801C8754(buffer1);
        self->field5D0 = buffer1;
    }
    size1 = fn_801C8D38(self->field5D0, arg1);
    size2 = fn_801C8E68(self->field5D0, arg1);
    b3 = fn_80204E5C(lbl_80532160, (int)size2);
    b1 = fn_80204E5C(lbl_80532160, (int)size1);
    fn_801C8B3C(self->field5D0, arg1, b1, size1, b3, size2);

    p = fn_80204E5C(lbl_80532160, 4);
    if (p) {
        if (p) *(void**)p = 0;
        self->field5E4 = p;
    }

    if (arg2 != 0) {
        q = fn_80204E5C(lbl_80532160, 0x2C);
        if (q) {
            if (q) q = fn_801CA838(q);
            self->field5E0 = q;
        }
        if (self->field8 == 2)
            v = 0x60000;
        else
            v = 0x6F800;
        fn_801CA8F0(self->field5E0, fn_80204E5C(lbl_80532160, v), v);
        fn_801CA274(self->field5D0, 0, self->field5E0, 0);
    } else {
        self->field5E0 = 0;
    }
}