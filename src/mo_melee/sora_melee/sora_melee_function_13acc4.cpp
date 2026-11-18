#include <it/item.h>
#include <ft/ft_manager.h>
#include <so/so_value_accesser.h>

#pragma force_active on

extern "C" const float lbl_27_rodata_1018[];

#define V8(p) \
    virtual void p##0(); virtual void p##1(); virtual void p##2(); virtual void p##3(); \
    virtual void p##4(); virtual void p##5(); virtual void p##6(); virtual void p##7();
#define V32(p) V8(p##0) V8(p##1) V8(p##2) V8(p##3)

class Object_vptr_0 {
public:
    virtual void slot0(); virtual void slot1(); virtual void slot2();
    virtual void slot3(); virtual void slot4();
    virtual int slot5(int, int, int, int);
    virtual void slot6(int, int, int, int);
    virtual void slot7(); virtual void slot8();
    virtual void slot9(); virtual void slot10();
    virtual void slot11(); virtual void slot12(); virtual void slot13();
    virtual void slot14(int, int, float);
    virtual void slot15(int, int);
    virtual void slot16();
    virtual void slot17(int, float);
    virtual void slot18(); virtual void slot19();
    virtual void slot20(); virtual void slot21(); virtual void slot22();
    virtual void slot23(); virtual void slot24(); virtual void slot25();
    virtual int slot26(BaseItem*);
    virtual void slot27(); virtual void slot28(); virtual void slot29();
    virtual void slot30(); virtual void slot31(); virtual void slot32();
    virtual void slot33(); virtual void slot34(); virtual void slot35();
    virtual void slot36(); virtual void slot37(); virtual void slot38();
    virtual void slot39(); virtual void slot40(); virtual void slot41();
    virtual void slot42(); virtual void slot43(); virtual void slot44();
    virtual void slot45(); virtual void slot46(); virtual void slot47();
    virtual void slot48(); virtual void slot49(); virtual void slot50();
    virtual void slot51(); virtual void slot52(); virtual void slot53();
    virtual void slot54();
    virtual void slot55(int, int, int, int);
};

class WorkModule {
public:
    virtual void slot0(); virtual void slot1(); virtual void slot2();
    virtual void slot3(); virtual void slot4(); virtual void slot5();
    virtual void slot6(); virtual void slot7(); virtual void slot8();
    virtual void slot9(); virtual void slot10(); virtual void slot11();
    virtual void slot12(); virtual void slot13(); virtual void slot14();
    virtual void slot15(); virtual void slot16();
    virtual unsigned int slot17(unsigned int);
    virtual void slot18(unsigned int);
};

struct Object_vptr_c_base { char pad[0xc]; };
class Object_vptr_c : public Object_vptr_c_base {
public:
    virtual void slot0(); virtual void slot1(); virtual void slot2();
    virtual void slot3(); virtual void slot4(); virtual void slot5();
    virtual void slot6(); virtual void slot7(); virtual void slot8();
    virtual void slot9(); virtual void slot10(); virtual void slot11();
    virtual void slot12();
    virtual void slot13(int, int, int);
};

struct Object_vptr_8_base { char pad[8]; };
class Object_vptr_8 : public Object_vptr_8_base {
public:
    virtual void slot0(); virtual void slot1(); virtual void slot2();
    virtual void slot3(); virtual void slot4(); virtual void slot5();
    virtual void slot6(); virtual void slot7(); virtual void slot8();
    virtual void slot9(); virtual void slot10(); virtual void slot11();
    virtual void slot12(); virtual void slot13(); virtual void slot14();
    virtual void slot15(int, int);
    virtual void slot16(); virtual void slot17(); virtual void slot18();
    virtual void slot19(); virtual void slot20(); virtual void slot21();
    virtual void slot22(); virtual void slot23(); virtual void slot24();
    virtual void slot25(); virtual void slot26(); virtual void slot27();
    virtual void slot28(); virtual void slot29(); virtual void slot30();
    virtual void slot31(); virtual void slot32(); virtual void slot33();
    virtual void slot34(); virtual void slot35(); virtual void slot36();
    virtual void slot37(); virtual void slot38(); virtual void slot39();
    virtual void slot40(); virtual void slot41(); virtual void slot42();
    virtual void slot43(); virtual void slot44(); virtual void slot45();
    virtual void slot46(); virtual void slot47(); virtual void slot48();
    virtual void slot49();
    virtual void slot50(float, unsigned int);
};

struct EffectModule {
    virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3();
    virtual void s4(); virtual void s5(); virtual void s6(); virtual void s7();
    virtual void effect(int, int, float*, float*, float*, float*, int, float, int);
    virtual void s9(); virtual void s10();
    virtual void request(int, int, float*, float*, int, int, int, float, int);
    virtual void s12(); virtual void s13(); virtual void s14(); virtual void s15();
    virtual void s16(); virtual void s17(); virtual void s18(); virtual void s19();
    virtual void s20(); virtual void s21(); virtual void s22(); virtual void s23();
    virtual void s24(); virtual void s25(); virtual void s26(); virtual void s27();
    virtual void s28(); virtual void s29(); virtual void s30(); virtual void s31();
    virtual void s32(); virtual void s33(); virtual void s34(); virtual void s35();
    virtual void s36(); virtual void s37();
    virtual void setFloat(int, float);
    virtual void s39(); virtual void s40(); virtual void s41(); virtual void s42();
    virtual void enable(int);
    virtual void disable(int);
};

struct Modules {
    char pad0[0x38];
    Object_vptr_8* damage;
    char pad3c[0x14];
    Object_vptr_0* sound;
    char pad54[8];
    Object_vptr_0* motion;
    char pad60[4];
    WorkModule* work;
    char pad68[0x20];
    EffectModule* effect;
    char pad8c[0x1c];
    Object_vptr_0* item;
    char padac[0xc];
    Object_vptr_8* other;
};

struct Access {
    char pad[0xd8];
    Modules* modules;
};

struct FighterBase { char pad[0x3c]; };

struct FighterObject : FighterBase {
    V32(a) V32(b) V32(c) V32(d) V32(e)
    V8(f0) V8(f1)
    virtual void f176();
    virtual void f221(int, int, float);
    virtual void f178(); virtual void f179(); virtual void f180();
    virtual void f181(); virtual void f182(); virtual void f183();
    virtual void f184();
    virtual Object_vptr_c* getOwner();

    char pad40[0x20];
    Access* access;
    char pad64[0xa8];
    int entryId;
};

struct ItemObject : FighterBase {
    V32(a) V8(b)
    virtual int getKind();

    char pad40[0x87c];
    int field8bc;
    char pad8c0[4];
    int field8c4;
    char pad8c8[0xc];
    unsigned char playerMask;
    char pad8d5[0x3453];
    int field3d28;
};

extern "C" {
    void fn_27_15A440(void*, int, int, int, int);
    float fn_27_112BBC(void*);
    float fn_27_112BC8(void*);
    float fn_27_112BD4(void*);
    void fn_27_112D90(void*, int, unsigned short);
    void fn_27_10D31C(ftManager*, int, int, int, int);
    void fn_27_138458(void*, int, int, int, int);
    void fn_27_28DB6C(void*, int, bool);
}

extern "C" int fn_27_13ACC4(
    FighterObject* fighter, ItemObject* item, int joint, signed char* result)
{
    int sound;
    ftManager* manager;
    int b;
    int a2;
    int entry;
    float ea[3];
    float eb[3];
    float ec[3];
    float ed[3];
    float lx2[3];
    float ly2[3];
    float ly[3];
    float lx[3];
    const float* data = lbl_27_rodata_1018;
    BaseItem* baseItem = (BaseItem*)item;
    Access* access = fighter->access;
    int kind = item->getKind();
    int flags = baseItem->getParam((itValueAccesser::ParamInt)0x5bce);
    int effect = -1;

    fn_27_15A440((char*)fighter + 0x13c, kind, item->field8c4,
                 item->field3d28, item->field8bc);

    if (flags & 0x80) {
        float value = baseItem->getParam((itValueAccesser::ParamFloat)0xdad);
        switch (kind) {
        case 0x40:
            value += fn_27_112BBC(fighter->getOwner());
            break;
        case 0x24:
            value += fn_27_112BC8(fighter->getOwner());
            break;
        case 0x20:
            value += fn_27_112BD4(fighter->getOwner());
            break;
        }

        Access* current = fighter->access;
        current->modules->damage->slot50(-value, 0);
        if (-value < data[12]) {
            Access* low = fighter->access;
            low->modules->sound->slot5(0x12, 0, 0, 0);
            low->modules->effect->setFloat(0x1f, data[12]);
            ly[0] = data[12];
            ly[1] = data[12];
            ly[2] = data[12];
            lx[0] = data[12];
            lx[1] = data[12];
            lx[2] = data[12];
            EffectModule* module = low->modules->effect;
            float scale = soValueAccesser::getConstantFloat(
                (soModuleAccesser*)low, 0xbe9, 0);
            module->request(0x36, 0, lx, ly, 0, 0, 0, scale, -1);
        } else {
            current->modules->motion->slot55(0xd, 0, 0, -1);
            sound = current->modules->sound->slot5(0x3b, 0, 0, 0);
            if (sound >= 0) {
                current->modules->sound->slot14(sound, 0, data[15]);
                current->modules->sound->slot17(sound, data[36]);
            }
            ly2[0] = data[12];
            ly2[1] = data[12];
            ly2[2] = data[12];
            lx2[0] = data[12];
            lx2[1] = data[12];
            lx2[2] = data[12];
            current->modules->effect->request(
                0x61, -2, lx2, ly2, 0, 0, 0, data[13], -1);
        }
    }

    if (flags & 0x2000) {
        int sound2 = baseItem->getParam((itValueAccesser::ParamInt)0x5bd2);
        access->modules->sound->slot5(sound2, 0, 0, 0);
    }

    switch (kind) {
    case 0x14: {
        unsigned char variation = (unsigned char)item->field8c4;
        *result = access->modules->item->slot26(baseItem);
        if (g_ftManager->addDragoon(fighter->entryId, variation) == 1) {
            access->modules->item->slot6(0x15, 0, 1, 0);
        }
        effect = 0x35;
        access->modules->sound->slot5(0x1fd0, 0, 0, 0);
        break;
    }
    case 0x27:
        fighter->f221(1, -1, data[16]);
        access->modules->sound->slot5(0x1f8a, 0, 0, 0);
        break;
    case 0x17:
        access->modules->sound->slot5(0xd7, 0, 0, 0);
        fn_27_112D90(fighter->getOwner(), kind, (unsigned short)item->field8c4);
        effect = 0x35;
        break;
    case 0x33:
        access->modules->sound->slot5(0xd6, 0, 0, 0);
        fn_27_112D90(fighter->getOwner(), kind, (unsigned short)item->field8c4);
        effect = 0x35;
        break;
    case 0x0b:
        access->modules->sound->slot5(0xd8, 0, 0, 0);
        fn_27_112D90(fighter->getOwner(), kind, (unsigned short)item->field8c4);
        effect = 0x77;
        access->modules->effect->enable(0x0c);
        break;
    case 0x49:
        access->modules->effect->enable(0x0b);
        break;
    case 0x35:
        switch (baseItem->getParam((itValueAccesser::ParamInt)0x5bd0)) {
        case 0: {
            b = soValueAccesser::getConstantInt(
                (soModuleAccesser*)access, 0x5a7f, 0);
            manager = g_ftManager;
            entry = fighter->entryId;
            int a = soValueAccesser::getConstantInt(
                (soModuleAccesser*)access, 0x5a7e, 0);
            fn_27_10D31C(manager, entry, 1, a, b);
            access->modules->sound->slot5(0x1f3e, 0, 0, 0);
            break;
        }
        case 1: {
            int b = soValueAccesser::getConstantInt(
                (soModuleAccesser*)access, 0x5a7f, 0);
            int a = soValueAccesser::getConstantInt(
                (soModuleAccesser*)access, 0x5a7e, 0);
            fn_27_138458(fighter, 1, a, b, 1);
            access->modules->sound->slot5(0x1f3e, 0, 0, 0);
            break;
        }
        case 2: {
            b = soValueAccesser::getConstantInt(
                (soModuleAccesser*)access, 0x5a7f, 0);
            a2 = soValueAccesser::getConstantInt(
                (soModuleAccesser*)access, 0x5a7e, 0);
            Access* current = fighter->access;
            if (current->modules->work->slot17(0x12000028) == 1) {
                current->modules->effect->disable(8);
            }
            current->modules->effect->enable(8);
            current->modules->work->slot18(0x12000028);
            current->modules->other->slot15(a2, b);
            access->modules->sound->slot5(0x1f3f, 0, 0, 0);
            break;
        }
        }
        break;
    case 0x10:
        ((Fighter*)fighter)->setCurry(true, -1);
        break;
    }

    if (effect != -1) {
        ed[0] = data[12];
        ed[1] = data[12];
        ed[2] = data[12];
        ec[0] = data[12];
        ec[1] = data[12];
        ec[2] = data[12];
        eb[0] = data[12];
        eb[1] = data[12];
        eb[2] = data[12];
        ea[0] = data[12];
        ea[1] = data[12];
        ea[2] = data[12];
        access->modules->effect->effect(effect, joint, ea, eb, ec, ed, 0, data[13], 0);
    }

    int player = g_ftManager->getPlayerNo(fighter->entryId);
    if (!(item->playerMask & (1 << player)) && kind != 0x14 && !(flags & 0x200000)) {
        fighter->getOwner()->slot13(1, 0x1e, 0);
        fn_27_28DB6C(item, player, true);
    }
    return 1;
}
