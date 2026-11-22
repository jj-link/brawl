#include <types.h>
#include <gf/gf_camera.h>
#include <gm/gm_global.h>
#pragma force_active on

struct Vec3 { float x, y, z; };
struct Flags {
    unsigned char first : 1, second : 1, third : 1, fourth : 1;
    unsigned char fifth : 1, sixth : 1, seventh : 1, eighth : 1;
    unsigned char ninth : 1, tenth : 1, reserved : 6;
};
struct Param {
    int resource, team, teamOwner, teamAnother, index, owner;
    int reserved0, reserved1;
    Vec3 position;
    float facing;
    int parameter, variant, situation, status, reserved2, motion, reserved3;
    Flags flags;
};
struct Anim {
    int a;
    float b, c;
    unsigned char d, e, f, g;
};
class Obj8 {
public:
    char pad[8];
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
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
    virtual void slot30();
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
    virtual void slot55();
    virtual void slot56(void*, float);
};
class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
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
    virtual void slot30();
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
    virtual void slot50(int);
    virtual void slot51();
    virtual void slot52();
    virtual void slot53();
    virtual void slot54();
    virtual void slot55();
    virtual void slot56(int, int, int, float, float);
    virtual void slot57();
    virtual void slot58();
    virtual void slot59(int, float);
    virtual void slot60();
    virtual void slot61(int, float);
    virtual void slot62();
    virtual void slot63();
    virtual void slot64();
    virtual void slot65();
    virtual void slot66();
    virtual void slot67();
    virtual void slot68();
    virtual void slot69();
    virtual void slot70();
    virtual void slot71();
    virtual void slot72();
    virtual void slot73();
    virtual void slot74();
    virtual void slot75();
    virtual void slot76();
    virtual void slot77();
    virtual void slot78();
    virtual void slot79();
    virtual void slot80();
    virtual void slot81();
    virtual void slot82();
    virtual void slot83();
    virtual void slot84();
    virtual void slot85();
    virtual void slot86();
    virtual void slot87();
    virtual void slot88();
    virtual void slot89();
    virtual void slot90();
    virtual void slot91();
    virtual void slot92();
    virtual void slot93();
    virtual void slot94();
    virtual void slot95();
    virtual void slot96();
    virtual void slot97();
    virtual void slot98();
    virtual void slot99(int, int, int);
    virtual void slot100();
    virtual void slot101();
    virtual void slot102();
    virtual void slot103();
    virtual void slot104();
    virtual void slot105();
    virtual void slot106(void*);
};
struct Modules {
    char pad0[4];
    Obj8* m4;
    Object_vptr_0* m8;
    char pad1[0x54 - 0x0C];
    Object_vptr_0* m54;
    char pad2[0x88 - 0x58];
    Object_vptr_0* m88;
};
struct Access { char pad[0xd8]; Modules* modules; };
struct Object { char pad[0x60]; Access* access; };
struct CamMgr {
    char pad[0x114];
    float f114, f118, f11c, f120, f124, f128;
};
struct Item { float value; char pad[24]; };
struct Small { float value; float pad; };
extern "C" {
extern const float lbl_27_rodata_7FB4;
extern const float lbl_27_rodata_7FB8;
void fn_27_1D8370(void*, const Param*);
void* __memcpy(void*, const void*, unsigned long);
}
static inline void configure(Object* object, Small& a) {
    Item f, e, d, c, b;
    object->access->modules->m4->slot56(object->access, lbl_27_rodata_7FB8);
    object->access->modules->m88->slot50(1);
    object->access->modules->m54->slot99(3, 4, 1);

    gfCameraManager* manager = gfCameraManager::getManager();
    CamMgr* cam;
    switch ((u32)manager) {
    default:
        cam = (CamMgr*)gfCameraManager::getManager();
        break;
    case 0:
        cam = 0;
        break;
    }
    if (cam != 0) {
        *(float*)f.pad = cam->f114;
        b.value = cam->f118;
        c.value = cam->f11c;
        d.value = cam->f120;
        e.value = cam->f124;
        f.value = cam->f128;
        Anim anim;
        anim.a = 0;
        anim.b = lbl_27_rodata_7FB4;
        anim.c = lbl_27_rodata_7FB8;
        anim.d = 0;
        anim.e = 0;
        anim.f = 0;
        anim.g = 0;
        object->access->modules->m8->slot106(&anim);
        if ((u32)((((u8*)g_GameGlobal->getGlobalRecordMenuDatap())[0x28] >> 7) & 1) == 1) {
            object->access->modules->m8->slot56(1, 1, 0, lbl_27_rodata_7FB4, lbl_27_rodata_7FB8);
            object->access->modules->m8->slot59(1, lbl_27_rodata_7FB4);
            object->access->modules->m8->slot61(1, lbl_27_rodata_7FB8);
        }
    }
}
static inline void initialize(int resource, int team, int parameter, Object* object) {
    struct Combined { Vec3 position; Small a; } combined;
    Param p;

    combined.position.x = lbl_27_rodata_7FB4;
    combined.position.y = lbl_27_rodata_7FB4;
    combined.position.z = lbl_27_rodata_7FB4;
    p.resource = resource;
    p.team = team;
    p.teamOwner = team;
    p.teamAnother = team;
    p.index = -1;
    p.owner = -1;
    p.reserved0 = 0;
    p.reserved1 = 0;
    __memcpy(&p.position, &combined.position, sizeof(Vec3));
    p.facing = lbl_27_rodata_7FB4;
    p.parameter = parameter;
    p.variant = 0;
    p.status = 0x80;
    p.reserved2 = 0;
    p.motion = 0x35f;
    p.reserved3 = 0;
    p.flags.first = 1;
    p.flags.second = 0;
    p.flags.third = 0;
    p.flags.fourth = 0;
    p.flags.fifth = 1;
    p.flags.sixth = 0;
    p.flags.seventh = 0;
    p.flags.eighth = 0;
    p.flags.ninth = 0;
    p.flags.tenth = 0;
    p.situation = 7;
    fn_27_1D8370(object, &p);

    configure(object, combined.a);
}
extern "C" void fn_27_3B2570(Object* object, int resource, int team, int parameter) {
    initialize(resource, team, parameter, object);
}
