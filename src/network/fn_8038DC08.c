#pragma force_active on
extern int fn_80362578(void*, int);
extern void fn_80362DD4(int);
extern void fn_80362E4C(int);
extern void fn_80364034(int, void*, int);
extern void fn_80364340(int, void*, int);
extern void fn_803646CC(int, void*, void*, void*);
extern void fn_80365548(int, void*, void*, int);
extern char lbl_80490F90[];
extern char lbl_80490F9C[];
extern int lbl_8059FBE0;
extern int lbl_8059FBF0;
extern int lbl_8059FBF4;

typedef int (*fn_ptr_int)(void*);
typedef void (*fn_ptr_void)(void*);

struct Module {
    int pad0;
    int field4;
    int pad[3];
    fn_ptr_int func14;
    fn_ptr_int func18;
    int pad1C;
    fn_ptr_void func20;
};

struct Self {
    void* obj;
    int pad[5];
    int id;
    int pad2;
    struct Module* module;
};

int fn_8038DC08(struct Self* self) {
    int b;
    struct Module* mod;
    {
        int a;
        mod = self->module;
        a = mod->func14(self);
        if (a != 0) {
            return a;
        }
    }
    self->id = fn_80362578(&lbl_8059FBE0, 1);
    if (self->id == 0) {
        return 2;
    }
    fn_80364034(self->id, &lbl_8059FBF0, self->module->field4);
    fn_80365548(self->id, &lbl_8059FBF0, &lbl_8059FBF4, *(int*)((char*)self->obj + 0x14));
    fn_803646CC(self->id, &lbl_8059FBF0, &lbl_80490F90, (char*)self->obj + 0x18);
    fn_803646CC(self->id, &lbl_8059FBF0, &lbl_80490F9C, (char*)self->obj + 0x2C);
    b = mod->func18(self);
    if (b != 0) {
        fn_80362DD4(self->id);
        self->id = 0;
        if (mod->func20) {
            mod->func20(self);
        }
        return b;
    }
    fn_80364340(self->id, &lbl_8059FBF0, self->module->field4);
    fn_80362E4C(self->id);
    return 0;
}
