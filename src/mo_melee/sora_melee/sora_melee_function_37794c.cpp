#pragma force_active on

#include <so/so_value_accesser.h>

class WorkModule {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual int v4(int);
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18(u32);
};

class SituationModule {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual int v3();
    virtual void v4();
    virtual void v5();
    virtual void v6(int, int);
};

class CollisionHitModule {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30(int, int, int);
};

struct GroundPrefix {
    char pad[8];
};

class GroundInner : public GroundPrefix {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void v60();
    virtual void v61();
    virtual void v62();
    virtual void v63();
    virtual void v64();
    virtual void v65();
    virtual void v66();
    virtual void v67();
    virtual void v68();
    virtual void v69();
    virtual void v70();
    virtual void v71();
    virtual void v72();
    virtual void v73();
    virtual void v74();
    virtual void v75();
    virtual void v76();
    virtual void v77();
    virtual void v78();
    virtual void v79();
    virtual void v80();
    virtual void v81();
    virtual void v82();
    virtual void v83();
    virtual void v84();
    virtual void v85();
    virtual void v86();
    virtual void v87();
    virtual void v88();
    virtual void v89();
    virtual void v90();
    virtual void v91();
    virtual void v92();
    virtual void v93();
    virtual void v94();
    virtual void v95();
    virtual void v96();
    virtual void v97();
    virtual void v98();
    virtual void v99();
    virtual void v100();
    virtual void v101();
    virtual void v102();
    virtual void v103();
    virtual void v104();
    virtual void v105();
    virtual void v106();
    virtual void v107();
    virtual void v108();
    virtual void v109();
    virtual void v110();
    virtual void v111();
    virtual u32 v112(int);
};

class StatusModule {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34(int, void*);
};

struct ModuleEnumeration {
    char pad0[0x10];
    GroundInner* ground;
    SituationModule* situation;
    char pad1[8];
    CollisionHitModule* collisionHit;
    char pad2[0x40];
    WorkModule* work;
    char pad3[8];
    StatusModule* status;
};

struct ModuleAccesser {
    char pad[0xD8];
    ModuleEnumeration* modules;
};

struct FtManager {
    char pad[0x68];
    unsigned char flag;
};

struct GameGlobalInner {
    char pad[0x4924];
    unsigned char flag;
};

struct GameGlobal {
    char pad[0x30];
    GameGlobalInner* inner;
};

extern FtManager* g_ftManager;
extern GameGlobal* g_GameGlobal;

extern "C" void* getOwner__9ftManagerFi(void*, int);
extern "C" u32 fn_27_111F4C(void*);
extern "C" int getConstantInt__15soValueAccesserFP16soModuleAccesserUlUl(
    void*, u32, u32);

extern "C" void fn_27_37794C(
    ModuleAccesser* self, int arg1, unsigned int arg2) {
    u32 result;

    if (arg1 == 7) {
        FtManager* manager = g_ftManager;
        if (manager->flag == 1 &&
            ((g_GameGlobal->inner->flag >> 6) & 1) == 0) {
            int ownerId = self->modules->work->v4(0x10000000);
            void* owner = getOwner__9ftManagerFi(manager, ownerId);

            if (fn_27_111F4C(owner) == 1) {
                int value =
                    getConstantInt__15soValueAccesserFP16soModuleAccesserUlUl(
                        self, 0x5A3E, 0);
                self->modules->collisionHit->v30(value, 1, 0);
            }
            result = 0xE;
        } else {
            self->modules->work->v18(0x1200003E);
            self->modules->work->v18(0x1200001D);
            result = 0xBE;
        }
    } else {
        if (self->modules->ground->v112(0) == 1) {
            self->modules->situation->v6(0, 0);
        } else {
            self->modules->situation->v6(2, 0);
        }

        result = arg1 == 0
            ? 0x10E
            : (self->modules->situation->v3() == 0 ? arg2 : 0xE);
    }

    self->modules->status->v34(result, self);
}
