#pragma force_active on
struct Vec3f { float x, y, z; };
extern "C" Vec3f* fn_112_9F54(Vec3f*, float, float, float);
extern "C" void fn_27_135DE8(void*);
extern "C" const float lbl_112_rodata_4;
extern "C" const float lbl_112_rodata_8;

struct A88 { virtual void a0(); virtual void a1(); virtual void a2(); virtual void a3(); virtual void a4(); virtual void a5(); virtual void a6(); virtual void a7(); virtual void a8(); virtual void a9(); virtual void a10();
 virtual int f34(int, int, Vec3f*, Vec3f*, float, bool, bool, int, int); };
struct A64 { virtual void a0(); virtual void a1(); virtual void a2(); virtual void a3();
 virtual int f18(int); virtual int f1C(int, int); };
struct B50 { virtual void a0(); virtual void a1(); virtual void a2(); virtual void a3(); virtual void a4(); virtual void a5(); virtual void a6(); virtual void a7(); virtual void a8(); virtual void a9(); virtual void a10(); virtual void a11(); virtual void a12(); virtual void a13(); virtual void a14(); virtual void a15(); virtual void a16(); virtual void a17(); virtual void a18(); virtual void a19(); virtual void a20(); virtual void a21(); virtual void a22(); virtual void a23(); virtual void a24(); virtual void a25(); virtual void a26(); virtual void a27();
 virtual int f78(int);};
struct A28 { virtual void a0(); virtual void a1(); virtual void a2(); virtual void a3(); virtual void a4(); virtual void a5(); virtual void a6(); virtual void a7(); virtual void a8(); virtual void a9(); virtual void a10(); virtual void a11(); virtual void a12();
 virtual void f3C(int, int, int); };
struct E50 { virtual void a0(); virtual void a1(); virtual void a2(); virtual void a3(); virtual void a4();
 virtual int f1C(int, bool, bool, int); };
struct Mods { char p[0x28]; A28* m28; char p2[0x50-0x2c]; B50* m50; char p3[0x64-0x54]; A64* m64; char p4[0x88-0x68]; A88* m88; };
struct Ent { char p[0xd8]; Mods* mods; };
struct Obj { char p[0x60]; Ent* ent; };

extern "C" void fn_112_9DA0(Obj* self) {
    char* base = (char*)self + 0x30000;
    if (*(unsigned char*)(base - 0x684c) == 1) {
        if (*(int*)(base - 0x6850) == 3) {
            A88* m = self->ent->mods->m88;
            Vec3f b, a;
            m->f34(0x180010, 0x2c,
                fn_112_9F54(&b, lbl_112_rodata_8, lbl_112_rodata_8, lbl_112_rodata_8),
                fn_112_9F54(&a, lbl_112_rodata_8, lbl_112_rodata_8, lbl_112_rodata_8),
                lbl_112_rodata_4, false, true, 0, -1);
            int id = self->ent->mods->m64->f18(0x10000041);
            if (id == -1 || ((B50*)self->ent->mods->m50)->f78(id) == 0) {
                int r = ((E50*)self->ent->mods->m50)->f1C(0x2c8, false, false, 0);
                self->ent->mods->m64->f1C(r, 0x10000041);
            }
        }
    } else if (*(unsigned char*)(base - 0x684b) == 1) {
        self->ent->mods->m28->f3C(0, 0, *(int*)(base - 0x6850));
    }
    fn_27_135DE8(self);
}
