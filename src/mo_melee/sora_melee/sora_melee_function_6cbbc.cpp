#pragma force_active on
struct Node {
    virtual void unused();
    virtual char* get();
};
struct ModuleBase { char padding[8]; };
struct Module : ModuleBase {
    virtual void u0(); virtual void u1(); virtual void u2(); virtual void u3(); virtual void u4();
    virtual void u5(); virtual void u6(); virtual void u7(); virtual void u8(); virtual void u9();
    virtual void u10(); virtual void u11(); virtual void u12(); virtual void u13(); virtual void u14();
    virtual void u15(); virtual void u16(); virtual void u17(); virtual void u18(); virtual void u19();
    virtual void u20(); virtual void u21(); virtual void u22(); virtual void u23(); virtual void u24();
    virtual void u25(); virtual void u26(); virtual void u27(); virtual void u28(); virtual void u29();
    virtual void u30(); virtual void u31(); virtual void u32(); virtual void u33(); virtual void u34();
    virtual void u35(); virtual void u36(); virtual void u37(); virtual void u38(); virtual void u39();
    virtual void u40(); virtual void u41(); virtual void u42(); virtual void u43(); virtual void u44();
    virtual void u45(); virtual void u46(); virtual void u47(); virtual void u48(); virtual void u49();
    virtual void u50(); virtual void u51(); virtual void u52(); virtual void u53(); virtual void u54();
    virtual void u55(); virtual void u56(); virtual void u57(); virtual void u58(); virtual void u59();
    virtual void u60(); virtual void u61(); virtual void u62(); virtual void u63(); virtual void u64();
    virtual void u65(); virtual void u66(); virtual void u67(); virtual void u68(); virtual void u69();
    virtual void u70(); virtual void u71(); virtual void u72(); virtual void u73();
    virtual void call();
};
struct Modules { char padding[4]; Module* module; };
struct Data { char padding[0xD8]; Modules* modules; };
struct Accessor { char padding[0x44]; Data* data; };
struct Object { char padding[0x48]; Node* node; };

extern "C" Accessor* fn_27_6F30C(void*);

extern "C" void fn_27_6CBBC(Object* __restrict object) {
    char* result = object->node->get();
    fn_27_6F30C(result + 0x1C)->data->modules->module->call();
}
