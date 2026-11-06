#pragma force_active on
extern "C" {
extern void* lbl_27_bss_5780;
extern char lbl_27_data_248[];
extern char lbl_27_data_69C0[];
extern float lbl_27_rodata_1F14;
void* __dynamic_cast(void*, long, const void*, const void*, short);
void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
void* fn_27_22A914(void*);
unsigned int fn_27_22B444(void*, unsigned int, void*);
void* fn_27_13BF9C(void*, unsigned int, float);
}
class Object_vptr_0 {
public:
    virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3();
    virtual int slot4(unsigned int, void*); virtual void slot5(unsigned int, unsigned int);
    virtual void slot6(); virtual void slot7(); virtual void slot8(); virtual void slot9();
    virtual void slot10(); virtual void slot11(); virtual void slot12(); virtual void slot13();
    virtual void slot14(); virtual void slot15(); virtual void slot16(); virtual void slot17();
    virtual void slot18(); virtual void slot19(); virtual void slot20(); virtual void slot21();
    virtual void slot22(); virtual void slot23(); virtual void slot24(); virtual void slot25();
    virtual void slot26(); virtual void slot27(); virtual void slot28(); virtual void slot29();
    virtual void slot30(); virtual int slot31(int, void*); virtual void slot32(); virtual void slot33();
    virtual int slot34(int);
};
class FloatV {
    char pad[8];
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual float v18(int);
};
struct Out { int a; float f; unsigned short s; };
struct Access {
    char pad0[0x20]; Object_vptr_0* o20;
    char pad24[0x14]; void* o38;
    char pad3c[0x28]; Object_vptr_0* o64;
    char pad68[0x20]; Object_vptr_0* o88;
};
struct Fighter { char pad[8]; void* owner; char padc[0xcc]; Access* access; };
extern "C" void fn_27_155150(void* unused, Fighter* self, void* unused2, char* b) {
    Out out;
    if (lbl_27_bss_5780 == 0) {
        void* m = __nw__FUlQ25Heaps8HeapType(0x54, 2);
        if (m != 0) m = fn_27_22A914(m);
        lbl_27_bss_5780 = m;
    }
    if (fn_27_22B444(lbl_27_bss_5780, *(unsigned int*)(b + 4), &out) == 1) {
        if (out.f < lbl_27_rodata_1F14) {
            FloatV* o = (FloatV*)self->access->o38;
            float r = o->v18(0);
            if (r <= lbl_27_rodata_1F14) return;
        } else if (out.f > lbl_27_rodata_1F14) {
            if (self->access->o20->slot34(0)) return;
        }
        int res = self->access->o64->slot4(0x10000032, self->access);
        unsigned int flag;
        if (res == 0) flag = 1;
        else flag = self->access->o88->slot31(res, self->access) == 0;
        unsigned int t = (unsigned int)fn_27_13BF9C(__dynamic_cast(self->owner, 0x3c, lbl_27_data_69C0, lbl_27_data_248, 1), flag, out.f);
        if (flag == 1) self->access->o64->slot5(t, 0x10000032);
        self->access->o64->slot5(out.s, 0x10000026);
    }
}