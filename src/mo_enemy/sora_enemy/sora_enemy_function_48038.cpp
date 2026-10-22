#pragma force_active on
typedef unsigned char u8;

extern "C" {
void Report__14wnemCommonProcFPCce(const char*, ...);
void* __dynamic_cast(void*, long, const void*, const void*, short);
void changeProcFnc__10wnemSimpleFll(void*, long, long);
extern const char lbl_41_data_11F0[], lbl_41_data_12A4[];
extern const char lbl_41_data_ECE8[];
extern const float lbl_41_rodata_1030;
}

struct Base8 {
    int a;
    int b;
};

struct Obj0 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6(int, int);
    virtual void v7();
    virtual void v8();
    virtual float v9();
};

struct Obj8 : Base8 {
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
    virtual void v19(int, int);
    virtual unsigned char v20(int);
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
    virtual unsigned int v55(int, int);
};

struct Access {
    char pad[0xd8];
};

extern "C" void fn_41_48038(Base8* self, Access* arg1) {
    int var_r31;
    int flag = ((u8*)self)[0x2214];
    ((u8*)self)[0x2214] = 0;
    if (flag != 0) {
        Report__14wnemCommonProcFPCce(lbl_41_data_ECE8, arg1);
        Obj0* o = *(Obj0**)(*(char**)((char*)arg1 + 0xd8) + 0x14);
        o->v6(2, 1);
        return;
    }
    {
        Obj8* o = *(Obj8**)(*(char**)((char*)arg1 + 0xd8) + 0x10);
        if (o->v20(0)) {
            unsigned char* q = 0;
            void* t = *(void**)((char*)self + 0x2234);
            if (t) {
                q = (unsigned char*)t;
            }
            if (*q == 1) {
                Obj8* o2 = *(Obj8**)(*(char**)((char*)arg1 + 0xd8) + 0x10);
                o2->v19(6, 0);
            }
            var_r31 = 0;
            Obj8* c = (Obj8*)__dynamic_cast(*(void**)(*(char**)((char*)arg1 + 0xd8) + 0x10), 8, lbl_41_data_11F0, lbl_41_data_12A4, 1);
            if (c->v55(8, 0) == 1) {
                var_r31 = 1;
            } else {
                Obj0* o3 = *(Obj0**)(*(char**)((char*)arg1 + 0xd8) + 0xc);
                float f = o3->v9();
                if (lbl_41_rodata_1030 == f) {
                    if (c->v55(0x42, 0) == 1) {
                        var_r31 = 1;
                    }
                } else {
                    if (c->v55(0x84, 0) == 1) {
                        var_r31 = 1;
                    }
                }
            }
            if (var_r31 != 0) {
                changeProcFnc__10wnemSimpleFll(self, 0x40, 1);
            }
        }
    }
}
