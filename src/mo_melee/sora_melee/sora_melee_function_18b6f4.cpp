#include <it/it_manager.h>
#include <nw4r/g3d/g3d_resfile.h>
#pragma force_active on

struct LocalVec { float x,y,z; };
struct Param { int kind; float a,b; char c,d,e,f; };
class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual int slot4(int);
    virtual void slot5(int, int);
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11(int, int, LocalVec*, LocalVec*, int, int, int, int, float);
    virtual void slot12(int);
    virtual void slot13(int);
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18(int);
    virtual void slot19();
    virtual void slot20();
    virtual void slot21();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void slot25();
    virtual void slot26();
    virtual void slot27();
    virtual void slot28();
    virtual void slot29();
    virtual void slot30(Param*, float);
    virtual void slot31();
    virtual void slot32();
    virtual void slot33();
    virtual void slot34();
    virtual void slot35();
    virtual void slot36();
    virtual void slot37();
    virtual void slot38();
    virtual void slot39();
    virtual void slot40();
    virtual void slot41();
    virtual void slot42();
    virtual void slot43();
    virtual void slot44();
    virtual void slot45();
    virtual void slot46();
    virtual void slot47();
    virtual void slot48();
    virtual void slot49();
    virtual void slot50();
    virtual void slot51();
    virtual void slot52();
    virtual void slot53();
    virtual void slot54();
    virtual void slot55(int, int, int, int);
};
class Sound {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5(int, int, int, int);
};
struct Modules {
    char pad0[8];
    Object_vptr_0* motion;
    Object_vptr_0* other;
    char pad10[0x40];
    Sound* sound;
    char pad54[8];
    Object_vptr_0* slot5c;
    char pad60[4];
    Object_vptr_0* work;
    char pad68[0x20];
    Object_vptr_0* effect;
};
struct Accesser { char pad[0xd8]; Modules* modules; };
extern "C" float fn_27_18B520(Accesser*, int, int);
extern "C" void* fn_27_2AC0A4(itManager*, int);
extern "C" const float lbl_27_rodata_2578;
extern "C" const float lbl_27_rodata_257C;

extern "C" void fn_27_18B6F4(void*, Accesser* a) {
    int kind = a->modules->work->slot4(0x10000023);
    int sub = a->modules->work->slot4(0x10000024);
    switch (kind) {
    case 4: {
        a->modules->other->slot22();
        a->modules->work->slot13(0x11000009);
        fn_27_18B520(a, kind, sub);
        a->modules->work->slot13(0x1100000a);
        switch (sub) {
        case 1:
            a->modules->sound->slot5(0x2075,0,0,0);
            break;
        case 2: {
            LocalVec v2, v1;
            v1.x = lbl_27_rodata_257C; v1.y = lbl_27_rodata_257C; v1.z = lbl_27_rodata_257C;
            v2.x = lbl_27_rodata_257C; v2.y = lbl_27_rodata_257C; v2.z = lbl_27_rodata_257C;
            a->modules->effect->slot11(0x44,0x12e,&v2,&v1,0,0,0,-1,lbl_27_rodata_2578);
            break;
        }
        }
        a->modules->work->slot5(0,0x20000002);
        Param p;
        p.kind=0x14e; p.a=lbl_27_rodata_257C; p.b=lbl_27_rodata_2578;
        p.c=0; p.d=0; p.e=0; p.f=0;
        a->modules->motion->slot30(&p,lbl_27_rodata_257C);
        a->modules->work->slot18(0x22000010);
        break;
    }
    case 2: {
        a->modules->other->slot22();
        a->modules->work->slot13(0x11000009);
        a->modules->work->slot12(0x1100000b);
        a->modules->work->slot13(0x1100000a);
        a->modules->work->slot5(1,0x20000002);
        Param p;
        p.kind=0x14f; p.a=lbl_27_rodata_257C; p.b=lbl_27_rodata_2578;
        p.c=0; p.d=0; p.e=0; p.f=0;
        a->modules->motion->slot30(&p,lbl_27_rodata_257C);
        a->modules->work->slot18(0x22000010);
        switch (a->modules->work->slot4(0x10000024)) {
        case 1: a->modules->sound->slot5(0x2076,0,0,0); break;
        }
        break;
    }
    case 6: {
        a->modules->other->slot22();
        a->modules->work->slot13(0x11000009);
        fn_27_18B520(a,kind,sub);
        a->modules->work->slot13(0x1100000a);
        switch (sub) {
        case 1:
            fn_27_18B520(a,kind,1);
            a->modules->work->slot13(0x1100000a);
            a->modules->sound->slot5(0x2076,0,0,0);
            break;
        case 2: {
            LocalVec v2, v1;
            v1.x=lbl_27_rodata_257C; v1.y=lbl_27_rodata_257C; v1.z=lbl_27_rodata_257C;
            v2.x=lbl_27_rodata_257C; v2.y=lbl_27_rodata_257C; v2.z=lbl_27_rodata_257C;
            a->modules->effect->slot11(0x44,0x12e,&v2,&v1,0,0,0,-1,lbl_27_rodata_2578);
            break;
        }
        }
        a->modules->work->slot5(1,0x20000002);
        Param p;
        p.kind=0x14f; p.a=lbl_27_rodata_257C; p.b=lbl_27_rodata_2578;
        p.c=0; p.d=0; p.e=0; p.f=0;
        a->modules->motion->slot30(&p,lbl_27_rodata_257C);
        a->modules->work->slot18(0x22000010);
        break;
    }
    case 1: {
        a->modules->other->slot22();
        a->modules->work->slot13(0x11000009);
        a->modules->work->slot12(0x1100000b);
        a->modules->work->slot13(0x1100000a);
        a->modules->work->slot5(0,0x20000002);
        Param p;
        p.kind=0x14e; p.a=lbl_27_rodata_257C; p.b=lbl_27_rodata_2578;
        p.c=0; p.d=0; p.e=0; p.f=0;
        a->modules->motion->slot30(&p,lbl_27_rodata_257C);
        a->modules->work->slot18(0x22000010);
        switch (a->modules->work->slot4(0x10000024)) {
        case 1: a->modules->sound->slot5(0x2075,0,0,0); break;
        }
        break;
    }
    }
    int id = a->modules->work->slot4(0x20000002);
    itManager* manager = itManager::getInstance();
    nw4r::g3d::ResFile file(fn_27_2AC0A4(manager,id));
    nw4r::g3d::ResAnmChr anm = file.GetResAnmChr(0);
    float length = (float)(int)anm.ref().m_animLength;
    a->modules->work->slot5((int)(length - lbl_27_rodata_2578),0x20000001);
    a->modules->slot5c->slot55(13,0,0,-1);
}
