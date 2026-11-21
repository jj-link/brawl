#pragma force_active on
#include <it/it_manager.h>
#include <mt/mt_vector.h>

extern "C" {
extern const float lbl_27_rodata_4610;
extern char lbl_27_data_5CC90[];
}

struct Id {
    int kind;
    unsigned int index;
    Id(int k, unsigned int i) : kind(k), index(i) {}
};

struct Pair { unsigned int a, b; };

class PositionBase {
public:
    char pad[8];
};

class Position : public PositionBase {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27();
    virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31();
    virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35();
    virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39();
    virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43();
    virtual void v44(); virtual void v45(); virtual void v46(); virtual void v47();
    virtual void v48(); virtual void v49(); virtual void v50(); virtual void v51();
    virtual void v52(); virtual void v53(); virtual void v54(); virtual void v55();
    virtual void v56(); virtual void v57(); virtual void v58(); virtual void v59();
    virtual void v60(); virtual void v61(); virtual void v62(); virtual void v63();
    virtual void v64(); virtual void v65(); virtual void v66(); virtual void v67();
    virtual void v68(); virtual void v69(); virtual void v70(); virtual void v71();
    virtual void v72(); virtual void v73(); virtual void v74(); virtual void v75();
    virtual void v76(); virtual void v77(); virtual void v78(); virtual void v79();
    virtual void v80(); virtual void v81(); virtual void v82(); virtual void v83();
    virtual void v84(); virtual void v85();
    virtual Pair get(int);
};

class Work {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void v24();
    virtual float get();
    virtual void set(float);
};

class Owner {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual int get();
};

class Object_vptr_0 {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17();
    virtual void slot18(unsigned int);
};

struct Object_vptr_3c_base {
    char pad[0x3c];
};

class Object_vptr_3c : public Object_vptr_3c_base {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27();
    virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31();
    virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35();
    virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39();
    virtual void v40(); virtual void v41(); virtual void v42();
    virtual void slot43();
};

struct Class_5CC98_base {
    char pad[0x7c];
};

class Class_5CC98 : public Class_5CC98_base {
public:
    virtual void fn_27_296880();
    virtual Object_vptr_3c** fn_27_296224(int);
    virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5();
    virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13();
    virtual void v14(); virtual void v15();
};

class List {
public:
    void* vtable;
    void* secondary;
    unsigned int flags;
    char pad[0x30];
};

class ListVirtual {
public:
    virtual void v0();
    virtual Object_vptr_3c** at(int);
};

struct LocalFighter {
    char p0[0x8c0];
    int kind;
    char p1[4];
    int owner;
    int extra;
    char p2[0x4e4];
    Work work;
    char p3[0xc4];
    Position pos;
    char p4[0xd8];
    Owner ownerModule;
    char p5[0x1b48];
    Object_vptr_0 sw;
};

extern "C" {
bool fn_27_2A8E3C(itManager*, const Id&);
void fn_27_2A8C88(itManager*, Id, int);
bool fn_27_2AB9CC(itManager*, Id);
void fn_27_2AB6BC(itManager*, Id, int);
int fn_27_2AA880(itManager*, List*, Id, int, Vec3f*, Vec3f*, int, int, int);
int fn_27_2AA70C(itManager*, Id, int, Vec3f*, Vec3f*, int, int, int);
void fn_27_2A83B8(itManager*, itKind, int, int, int);
}

extern "C" void fn_27_28ED34(LocalFighter* self, int kind, const Vec2f* offset)
{
    Id id(0xff, 0);
    if (!fn_27_2A8E3C(itManager::getInstance(), Id(0xff, 0))) {
        fn_27_2A8C88(itManager::getInstance(), id, 0);
        return;
    }

    if (!fn_27_2AB9CC(itManager::getInstance(), id)) {
        fn_27_2AB6BC(itManager::getInstance(), id, 2);
        return;
    }

    Object_vptr_0* sw = &self->sw;
    int owner = self->owner;
    int ownerId = -1;
    union { Pair raw; Vec2f pos; } value;
    value.raw = self->pos.get(0);
    const Vec2f& pos = value.pos;
    Vec3f target = Vec3f(
        pos.m_x + offset->m_x,
        pos.m_y + offset->m_y,
        lbl_27_rodata_4610);

    if (self->kind == 0x2a || self->kind == 0)
        ownerId = self->ownerModule.get();

    if (self->kind == 0x54) {
        List list;
        list.vtable = lbl_27_data_5CC90;
        list.secondary = lbl_27_data_5CC90 + 0x48;
        list.flags &= 0xffff;

        Vec3f origin;
        origin.m_x = pos.m_x;
        origin.m_y = pos.m_y;
        origin.m_z = lbl_27_rodata_4610;
        if (fn_27_2AA880(itManager::getInstance(), &list, id, kind,
                         &origin, &target, owner, ownerId, self->extra) == 3) {
            for (int i = 0; i < ((int)((list.flags << 10) & 0xfc000000) >> 27); i++) {
                float f = self->work.get();
                Object_vptr_3c* entity =
                    *reinterpret_cast<ListVirtual*>(&list)->at(i);
                reinterpret_cast<Work*>((char*)entity + 0xdb4)->set(f);
                entity->slot43();
            }

            int i;
            int n = itManager::getInstance()->getItemNum(
                (itKind)0x58, 0, owner, -1) - 4;
            for (i = 0; i < n; i++)
                fn_27_2A83B8(itManager::getInstance(), (itKind)0x58, 0, owner, -1);
        }
    } else {
        Vec3f origin;
        origin.m_x = pos.m_x;
        origin.m_y = pos.m_y;
        origin.m_z = lbl_27_rodata_4610;
        if (fn_27_2AA70C(itManager::getInstance(), id, kind,
                         &origin, &target, owner, ownerId, self->extra) == 2)
            sw->slot18(0x22000006);
    }
}
