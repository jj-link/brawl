#pragma force_active on

typedef unsigned int u32;

struct Vec {
    float x;
    float y;
    float z;
};

struct Obj {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual int kind();
};

struct ModuleBase {
    char pad[8];
};

struct Module : ModuleBase {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void* get();
};

struct Target {
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
    virtual int get(int);
};

struct OwnerInner {
    char pad[0x28];
    void* value;
};

struct Context {
    char pad[8];
    OwnerInner* inner;
    char pad2[0xcc];
    Module** module;
};

extern "C" {
    extern char lbl_27_data_31AD8[];
    extern char lbl_27_data_C938[];
    extern char lbl_27_data_2C0C0[];
    extern char lbl_27_data_CBA0[];
    extern float lbl_27_rodata_79F0;
    extern char g_ftCommonDataAccesser[];

    void* __dynamic_cast(void*, long, const void*, const void*, short);
    void* getData__20ftCommonDataAccesserCF6ftKind(const void*, int);

    void fn_27_1E1B14(
        void*, void*, int, void*, int, int, Vec*, u32,
        u32, int, int, int, int, int, int, int, int, int
    );

    int fn_27_35A0EC(void* self, Obj* obj, Context* ctx) {
        if (obj->kind() == 13) {
            obj = (Obj*)__dynamic_cast(
                obj, 0, lbl_27_data_31AD8, lbl_27_data_C938, 0
            );
            if (!obj)
                return 0;

            Vec v;
            v.x = lbl_27_rodata_79F0;
            v.y = lbl_27_rodata_79F0;
            v.z = lbl_27_rodata_79F0;

            Module* mod = *(ctx->module);
            void* owner = ctx->inner->value;
            void* data = getData__20ftCommonDataAccesserCF6ftKind(
                g_ftCommonDataAccesser, 5
            );
            void* params = *(void**)(*(void**)((char*)data + 0x64));
            Target* target = (Target*)__dynamic_cast(
                mod->get(), 0, lbl_27_data_2C0C0, lbl_27_data_CBA0, 1
            );
            int id = target->get(0x16);

            fn_27_1E1B14(
                obj, owner, id, (char*)params + 0x268,
                0, 0, &v, 65535, 65535, 0, 1, 0, -1, 0, 0, 2, 0, 0
            );
            return 1;
        }
        return 0;
    }
}