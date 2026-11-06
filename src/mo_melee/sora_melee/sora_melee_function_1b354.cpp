#pragma force_active on

class Obj6C {
public:
    virtual void v0();
    virtual void v1();
    virtual void v4(void* obj168, short* sp, float val);
    virtual void v5();
    virtual void v6();
    virtual void v7(short* ptr, void* obj168, int a, int b, float val);
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11(void* local, void* obj168, short* ptr);
};

class ObjB8_base { public: char pad[8]; };
class ObjB8 : public ObjB8_base {
public:
    virtual void m2(); virtual void m3();
    virtual void m4(); virtual void m5(); virtual void m6(); virtual void m7();
    virtual void m8(); virtual void m9(); virtual void m10(); virtual void m11();
    virtual void m12(); virtual void m13(); virtual void m14();
    virtual float m15();
};

class Obj54 {
public:
    virtual void t0(); virtual void t1(); virtual void t2(); virtual void t3(); virtual void t4();
    virtual void t5(); virtual void t6(); virtual void t7(); virtual void t8();
    virtual unsigned int a11(int zero);
    virtual void t12(); virtual void t13(); virtual void t14(); virtual void t15();
    virtual void t16(); virtual void t17(); virtual void t18(); virtual void t19();
    virtual void t20(); virtual void t21(); virtual void t22(); virtual void t23();
    virtual void t24(); virtual void t25(); virtual void t26(); virtual void t27();
    virtual void t28(); virtual void t29(); virtual void t30(); virtual void t31();
    virtual void t32(); virtual void t33(); virtual void t34(); virtual void t35();
    virtual void t36(); virtual void t37(); virtual void t38(); virtual void t39();
    virtual void t40(); virtual void t41(); virtual void t42(); virtual void t43();
    virtual void a44(int zero);
    virtual void t45(); virtual void t46(); virtual void t47(); virtual void t48();
    virtual void t49(); virtual void t50(); virtual void t51(); virtual void t52();
    virtual void t53(); virtual void t54(); virtual void t55(); virtual void t56();
    virtual void t57(); virtual void t58(); virtual void t59(); virtual void t60();
    virtual void t61(); virtual void t62(); virtual void t63(); virtual void t64();
    virtual void t65(); virtual void t66(); virtual void t67(); virtual void t68();
    virtual void t69(); virtual void t70(); virtual void t71(); virtual void t72();
    virtual void t73(); virtual void t74(); virtual void t75(); virtual void t76();
    virtual void t77(); virtual void t78(); virtual void t79(); virtual void t80();
    virtual void t81(); virtual void t82(); virtual void t83(); virtual void t84();
    virtual void t85(); virtual void t86(); virtual void t87(); virtual void t88();
    virtual void t89(); virtual void t90(); virtual void t91(); virtual void t92();
    virtual void t93(); virtual void t94(); virtual void t95(); virtual void t96();
    virtual void t97(); virtual void t98(); virtual void t99(); virtual void t100();
    virtual void t101(); virtual void t102(); virtual void t103(); virtual void t104();
    virtual void t105(); virtual void t106(); virtual void t107(); virtual void t108();
    virtual void a109(int zero, void* local, int mode, short* ptr);
};

class ObjD8 {
public:
    char pad0[0x54];
    Obj54* obj54;
    char pad1[0x14];
    Obj6C* obj6C;
    char pad2[0x48];
    ObjB8* objB8;
};

class Obj168 {
public:
    char pad[0xd8];
    ObjD8* objD8;
};

class Self {
public:
    virtual void s2(); virtual void s3();
    virtual void s4(); virtual void s5(); virtual void s6(); virtual void s7();
    virtual float s8();
    virtual void s9(); virtual void s10(); virtual void s11(); virtual void s12();
    virtual void s13(); virtual void s14(); virtual void s15(); virtual void s16();
    virtual void s17(); virtual void s18(); virtual void s19(); virtual void s20();
    virtual void s21(); virtual void s22(); virtual void s23(); virtual void s24();
    virtual void s25(); virtual void s26(); virtual void s27(); virtual void s28();
    virtual void s29(); virtual void s30(); virtual void s31(); virtual void s32();
    virtual void s33(); virtual void s34(); virtual void s35(); virtual void s36();
    virtual void s37(); virtual void s38(); virtual void s39(); virtual void s40();
    virtual void s41(); virtual void s42(); virtual void s43(); virtual void s44();
    virtual void s45(); virtual void s46(); virtual void s47(); virtual void s48();
    virtual void s49(); virtual void s50(); virtual void s51(); virtual void s52();
    virtual void s53(); virtual void s54(); virtual void s55(); virtual void s56();
    virtual void s57(); virtual void s58(); virtual void s59(); virtual void s60();
    virtual void s61(); virtual void s62(); virtual void s63(); virtual void s64();
    virtual void s65(); virtual void s66(); virtual void s67(); virtual void s68();
    virtual void s69(); virtual void s70(); virtual void s71(); virtual void s72();
    virtual void s73(); virtual void s74(); virtual void s75(); virtual void s76();
    virtual void s77(); virtual void s78(); virtual void s79(); virtual void s80();
    virtual void s81(); virtual void s82(); virtual void s83(); virtual void s84();
    virtual void s85(); virtual void s86(); virtual void s87();
    virtual void s88(void* obj168);
    char pad0[0x38];
    int unk3C;
    float unk40;
    char pad1[0x124];
    Obj168* obj168;
};

class Local {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    void* b;
    unsigned int c;
};

extern "C" {
void __construct_array(void*, void (*)(void*), void (*)(void*), unsigned long, int);
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
unsigned char* fn_27_20FE4(void*, int, int);
void fn_27_1CBD0(void*);
void* fn_27_1CBE4(void*, int);
extern unsigned char lbl_27_data_1760[];
extern const float lbl_27_rodata_344;
}

extern "C" void fn_27_1B354(Self* self, int mode, unsigned int flag1, short* ptr, unsigned int flag2, float val) {
    unsigned char flags = fn_27_20FE4((char*)self + 0x34, mode, 1)[1];
    if (mode == -1) {
        Obj168* obj168 = self->obj168;
        obj168->objD8->obj6C->v7(ptr, obj168, -1, 0, lbl_27_rodata_344);
        return;
    }
    if ((flags & 8) && self->obj168->objD8->obj54->a11(0) == 1U) {
        self->obj168->objD8->obj54->a44(0);
        unsigned int buf[3];
        *(void**)buf = lbl_27_data_1760;
        ((Local*)buf)->b = lbl_27_data_1760 + 0x48;
        ((Local*)buf)->c &= 0x1fff;
        char arr[0xf0];
        __construct_array(arr, (void (*)(void*))fn_27_1CBD0, (void (*)(void*))fn_27_1CBE4, 0xc, 0x14);
        self->obj168->objD8->obj54->a109(0, buf, mode, ptr);
        ((Local*)buf)->f4();
        Obj168* obj168 = self->obj168;
        obj168->objD8->obj6C->v11(buf, obj168, ptr);
        __destroy_arr(arr, (void (*)(void*, int))fn_27_1CBE4, 0xc, 0x14);
    } else {
        float f30 = val;
        if (flag2 == 1U && self->unk3C != 0) {
            f30 = self->unk40;
            float f31 = self->obj168->objD8->objB8->m15();
            float s = self->s8();
            f30 = f30 - s * f31;
        }
        Obj168* obj168 = self->obj168;
        obj168->objD8->obj6C->v7(ptr, obj168, mode, 0, f30);
    }
    if (flag1 == 1U) {
        short sp8 = *ptr;
        Obj168* obj168 = self->obj168;
        obj168->objD8->obj6C->v4(obj168, &sp8, lbl_27_rodata_344);
        self->s88(self->obj168);
    }
}
