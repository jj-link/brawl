#pragma force_active on

extern "C" {
    void* fn_120_8044(void);
    unsigned int fn_27_5BEA8(void);
    void fn_120_8B7C(void*, void*);
    int* fn_120_7F08(void);
    void fn_27_3A2DD8(void*, void*);
    void fn_27_12E7C8(void*);
}

class Obj44 {
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
    virtual int v9();
    virtual void v10();
};

class Obj64 {
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
    virtual int v17(unsigned int);
    virtual void v18();
    virtual void v19(unsigned int);
};

struct Pad8 {
    char pad[8];
};

class Obj8type {
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
    virtual void v40(int);
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
    virtual int v52(int);
};

class ObjB8type : public Pad8 {
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
    virtual int v14();
};

struct Container {
    char pad0[8];
    Obj8type* obj8;
    char pad1[0x38];
    Obj44* obj44;
    char pad2[0x1C];
    Obj64* obj64;
    char pad3[0x50];
    ObjB8type* objB8;
};

struct Resource {
    char pad0[0xD8];
    Container* container;
};

struct Self {
    char pad0[0x60];
    Resource* resource;
};

extern "C" void fn_120_8098(Self* self) {
    Resource* res = self->resource;
    fn_120_8044();
    if (fn_27_5BEA8() == 1) {
        if (res->container->obj44->v9() == 0) {
            if (res->container->objB8->v14() == 0) {
                if (res->container->obj64->v17(0x12000042) != 0) {
                    fn_120_8B7C(self, res);
                }
                fn_27_3A2DD8(fn_120_7F08(), res);
            }
            if (self->resource->container->obj64->v17(0x12000041) != 0) {
                if (self->resource->container->obj8->v52(2) != 0) {
                    self->resource->container->obj8->v40(2);
                    self->resource->container->obj64->v19(0x12000041);
                }
            }
        }
    }
    fn_27_12E7C8(self);
}