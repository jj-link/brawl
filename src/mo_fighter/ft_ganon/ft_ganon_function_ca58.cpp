#pragma force_active on
typedef unsigned long u32;

class soModuleAccesser;
class StageObject;

class soValueAccesser {
public:
    float getVariableFloat(soModuleAccesser*, u32, u32);
};

class gfTask {
public:
    static void* getTask(int id);
};

class soExternalValueAccesser {
public:
    static void* getModuleAccesser(StageObject* obj);
};

class WorkMod {
public:
    virtual void v2() = 0;
    virtual void v3() = 0;
    virtual void v4() = 0;
    virtual void v5(u32, void*) = 0;
    virtual int v6(u32) = 0;
    virtual void v7(void*, u32) = 0;
    virtual void v8() = 0;
    virtual void v9() = 0;
    virtual void v10() = 0;
    virtual void v11() = 0;
    virtual void v12() = 0;
    virtual void v13() = 0;
    virtual void v14() = 0;
    virtual void v15() = 0;
    virtual void v16() = 0;
    virtual void v17() = 0;
    virtual void v18() = 0;
    virtual int v19(u32) = 0;
    virtual void v20(u32) = 0;
};

class OwnerMod {
public:
    virtual void v2() = 0;
    virtual void v3() = 0;
    virtual void v4() = 0;
    virtual void v5() = 0;
    virtual void v6() = 0;
    virtual void v7() = 0;
    virtual void v8() = 0;
    virtual void v9() = 0;
    virtual void v10() = 0;
    virtual void v11() = 0;
    virtual int v12(u32) = 0;
    virtual void v13() = 0;
    virtual void v14() = 0;
    virtual void v15() = 0;
    virtual void v16() = 0;
    virtual void v17() = 0;
    virtual void v18() = 0;
    virtual void v19() = 0;
    virtual void v20() = 0;
    virtual void* v21(u32) = 0;
};

extern "C" void* __dynamic_cast(void*, long, const void*, const void*, short);

extern float lbl_109_rodata_1C;
extern char lbl_109_data_2148[];
extern char lbl_109_data_2248[];

#define OWNER(self) (*(char**)((char*)(self) + 0xd8))
#define FIELD(p, off) (*(void**)((char*)(p) + (off)))

extern "C" void fn_109_CA58(void*, soValueAccesser* self, u32, u32 arg3) {
    WorkMod* work = (WorkMod*)FIELD(OWNER(self), 0x64);
    if (self->getVariableFloat(0, 0, arg3) > lbl_109_rodata_1C) {
        if (work->v19(0x22000019) == 0) {
            if (((OwnerMod*)FIELD(OWNER(self), 0x54))->v12(0) != 0) {
                work->v7(((OwnerMod*)FIELD(OWNER(self), 0x54))->v21(0), 0x20000005);
                work->v20(0x22000019);
            }
        }
    }
    if (work->v19(0x22000017) != 0 && work->v19(0x22000018) == 0) {
        int tid = work->v6(0x20000005);
        void* task = gfTask::getTask(tid);
        if (task != 0) {
            void* obj = __dynamic_cast(task, 0x3c, lbl_109_data_2148, lbl_109_data_2248, 0);
            if (obj != 0) {
                void* mod = soExternalValueAccesser::getModuleAccesser((StageObject*)obj);
                WorkMod* o = (WorkMod*)FIELD(FIELD(mod, 0xd8), 0x70);
                o->v5(0x49, mod);
                work->v20(0x22000018);
            }
        }
    }
}
