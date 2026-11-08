#pragma force_active on
typedef unsigned int u32;
typedef signed int s32;
typedef unsigned short u16;
typedef unsigned char u8;

extern "C" const float lbl_27_rodata_C58;

struct Accesser;
struct Modules;

class Module6C {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4(void*, const Accesser*, const Modules*, float);
    virtual void v5();
    virtual void v6(void*, void*, s32, float);
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual float v13(void*);
};

class ModuleAC {
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
    virtual void v9(s32);
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15(u16, u8);
};

class Object78 {
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
    virtual void v9(void*);
};

struct Entry {
    s32 field0;
    u16 field4;
    u8 field6;
    u8 field7;
};

struct Modules {
    char pad[0x6C];
    Module6C* module6c;
    char pad2[0x3C];
    ModuleAC* moduleac;
};

struct Accesser {
    char pad[0xD8];
    Modules* modules;
};

class Self {
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
    virtual s32 v42(s32);

    char pad0[0x40];
    Accesser* m_accesser;
    char pad1[0x24];
    Entry* m_entries;
    void* m_0x70;
    s32 m_index;
    Object78 m_obj78;
};

struct Pair {
    s32 first;
    float second;
};

extern "C" void fn_27_9A380(Self* self, s32 arg1, float farg) {
    if (self->m_index == -1 ||
        self->m_entries[self->m_index].field4 <=
            self->m_entries[arg1].field4) {
        if (self->m_index != -1 &&
            self->m_entries[self->m_index].field7 != 0 &&
            self->v42(arg1) == 0) {
            float result = self->m_accesser->modules->module6c->v13(
                self->m_0x70);
            Pair p;
            p.first = self->m_index;
            p.second = result;
            self->m_obj78.v9(&p);
        }

        self->m_accesser->modules->module6c->v6(
            self->m_0x70, self->m_accesser, arg1, farg);

        const Accesser* accesser = self->m_accesser;
        const Modules* const modules = accesser->modules;
        modules->module6c->v4(
            self->m_0x70, accesser, modules, lbl_27_rodata_C58);

        self->m_index = arg1;
        self->m_accesser->modules->moduleac->v9(0);
        self->m_accesser->modules->moduleac->v15(
            self->m_entries[self->m_index].field4,
            self->m_entries[self->m_index].field6);
    } else if (self->m_entries[arg1].field7 != 0 &&
               self->v42(arg1) == 0) {
        Pair p;
        p.first = arg1;
        p.second = farg;
        self->m_obj78.v9(&p);
    }
}
