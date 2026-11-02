#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;

extern "C" {
void* __dynamic_cast(void*, long, const void*, const void*, short);
extern char __RTTI__5Enemy[];
extern char __RTTI__11StageObject[];
extern char lbl_41_data_644[];
extern char lbl_41_data_6A8[];
extern float lbl_41_rodata_DC0;
u32 fn_41_1794C(void* p, int idx);
void fn_41_17D60(void* a, int b);
void fn_41_17DA8(void* a, int b);
void fn_41_2A96C(char* self);
void fn_41_2A9EC(void* unused, void* self, void* obj);
}

struct V3 {
    float x;
    float y;
    float z;
};

extern "C" V3 fn_41_6270(void* obj, int id);

struct Flags34 {
    u8 f : 3;
    u8 a : 1;
    u8 b : 1;
    u8 r : 3;
};

struct SelfVt {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual int f7();
};

struct ObjA {
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
    virtual int f19();
    virtual void f20();
    virtual void f21();
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
    virtual void f36();
};

struct ObjB {
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
    virtual u32 f19(u32);
};

struct PadBase {
    int pad0;
    int pad4;
};

struct ObjC : PadBase {
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
    virtual void f31();
};

extern "C" void fn_41_2AA70(char* self, int arg1) {
    if (((SelfVt*)self)->f7() != 0 && arg1 != 0) {
        int r28 = 1;
        ObjA* r31;
        void* r30 = __dynamic_cast(*(void**)(*(char**)(*(char**)(self + 0x1C) + 0xD8) + 0x7C), 0, lbl_41_data_644, lbl_41_data_6A8, (short)r28);
        fn_41_17D60(r30, *(int*)(self + 0x44));
        fn_41_17DA8(r30, *(int*)(self + 0x44));
        r31 = *(ObjA**)(*(char**)(*(char**)(self + 0x1C) + 0xD8) + 0x0C);
        void* r27 = __dynamic_cast(*(void**)(*(char**)(self + 0x1C) + 0x8), 0x3C, __RTTI__5Enemy, __RTTI__11StageObject, (short)r28);
        ObjB* ob = *(ObjB**)(*(char**)(*(char**)(self + 0x1C) + 0xD8) + 0x64);
        r28 = ob->f19(0x12000003);
        r31->f20();
        const V3& v = fn_41_6270(r27, r28);
        Flags34* fl = (Flags34*)(self + 0x34);
        if (fl->f == 1 && ((v.y >= lbl_41_rodata_DC0 && *(float*)(self + 0x2C) < lbl_41_rodata_DC0) || (v.y <= lbl_41_rodata_DC0 && *(float*)(self + 0x2C) > lbl_41_rodata_DC0))) {
            if (fl->a == 1 && r31->f19() == 0) {
                fl->b = 1;
                fn_41_2A9EC(self, r30, r31);
            }
            fl->f = 2;
        }
        *(float*)(self + 0x2C) = v.y;
        if (fn_41_1794C(r30, *(int*)(self + 0x44)) == 1) {
            r31->f21();
            if (fl->a == 1 && fl->b == 0) {
                fn_41_2A9EC(self, r30, r31);
            }
            char* o38 = *(char**)(*(char**)(*(char**)(self + 0x1C) + 0xD8) + 0x38);
            ((ObjC*)o38)->f31();
            fn_41_2A96C(self);
            r31->f36();
        }
    }
}
