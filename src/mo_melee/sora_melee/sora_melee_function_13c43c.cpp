#pragma force_active on

class Module {
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
    virtual void v79(int);
};

struct Modules {
    char pad[8];
    Module* module;
};

struct Owner {
    char pad[0xD8];
    Modules* modules;
};

struct Context {
    char pad[0x60];
    Owner* owner;
};

extern "C" int getParam__8BaseItemFQ215itValueAccesser8ParamInt(void*, int);
extern "C" void fn_27_13C530(void*, unsigned int, int);

extern "C" void fn_27_13C43C(Context* self, void* item, int arg2, unsigned int arg3) {
    int param = getParam__8BaseItemFQ215itValueAccesser8ParamInt(item, 0x5B6A);

    switch (param) {
    case 3:
    case 4:
    case 5:
    case 6:
        if (arg3 == 1) {
            unsigned int index;
            switch (param) {
            case 3: index = 0; break;
            case 4: index = 1; break;
            case 5: index = 2; break;
            case 6: index = 3; break;
            }
            fn_27_13C530(self, index, arg2);
        } else {
            self->owner->modules->module->v40(0);
            self->owner->modules->module->v79(0);
        }
        break;
    }
}
