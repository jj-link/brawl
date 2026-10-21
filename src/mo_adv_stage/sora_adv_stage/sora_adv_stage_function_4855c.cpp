#pragma force_active on

extern "C" {
void fn_80107E68(void*);
void fn_8010ED7C(void*);
void Destroy__Q34nw4r3g3d6G3dObjFv(void*);
void exit__6gfTaskFv(void*);
void __dt__6gfTaskFv(void*, int);
void __dl__FPv(void*);

extern void* g_IfAdvMngr;
extern void* lbl_805A0348;
extern char lbl_40_data_184C4[];
}

struct Object {
    char pad[0x5C];
    virtual ~Object();
};

struct Stage {
    char pad0[0x3C];
    void* vtable;
    char pad40[0x1BC];
    void* task1FC;
    void* task200;
    char pad204[0x20];
    Object* object224;
    void* object228;
};

extern "C" Stage* fn_40_4855C(Stage* self, int flag) {
    if (self) {
        self->vtable = lbl_40_data_184C4;
        fn_80107E68(g_IfAdvMngr);
        fn_8010ED7C(lbl_805A0348);

        if (&self->object228) {
            if (self->object228)
                Destroy__Q34nw4r3g3d6G3dObjFv(self->object228);
            self->object228 = 0;
        }

        if (&self->object224) {
            delete self->object224;
        }

        if (&self->task200) {
            if (self->task200)
                exit__6gfTaskFv(self->task200);
            self->task200 = 0;
        }

        if (&self->task1FC) {
            if (self->task1FC)
                exit__6gfTaskFv(self->task1FC);
            self->task1FC = 0;
        }

        __dt__6gfTaskFv(self, 0);
        if (flag > 0)
            __dl__FPv(self);
    }
    return self;
}
