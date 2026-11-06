#pragma force_active on

#include <so/so_module_accesser.h>

struct TargetBase {
    char padding[0x3c];
};

class Target : public TargetBase {
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
    virtual void action(int);
};

class TargetList {
public:
    virtual void v0();
    virtual void v1();
    virtual Target** get(int);
    virtual int size();
};

class FloatModule {
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
    virtual float getFloat();
};

extern "C" {
extern const char lbl_113_data_61C[];
extern const char lbl_113_data_2950[];
void* __dynamic_cast(void*, long, const void*, const void*, short);
int fn_113_243CC(void*);
Target* fn_113_244FC(void*);
TargetList* fn_113_24550(void*);
void fn_113_24D34(void*, Target*, float);
void fn_113_24D8C(void*, Target*, float);
void fn_113_10DD0(void*);
}

extern "C" void fn_113_111B0(void*, soModuleAccesser* accesser) {
    void* target = __dynamic_cast(
        *(void**)((char*)accesser + 8), 0x3c,
        lbl_113_data_61C, lbl_113_data_2950, short(0));

    if (target) {
        void* manager = (char*)target + 0x1fd08;
        if (accesser->getWorkManageModule().isFlag(0x22000010)) {
            accesser->getWorkManageModule().offFlag(0x22000010);
            if (fn_113_243CC(manager) > 0) {
                switch (accesser->getStatusModule().getStatusKind()) {
                case 0x2c: {
                    float lr = accesser->getPostureModule().getLr();
                    fn_113_24D34(manager, fn_113_244FC(manager), lr);
                    fn_113_244FC(manager)->action(0x10);
                    break;
                }
                case 0x32:
                    fn_113_244FC(manager)->action(0x1c);
                    break;
                case 0x2f: {
                    TargetList* list = fn_113_24550(manager);
                    (*list->get(0))->action(0x13);
                    if (list->size() > 1) {
                        (*list->get(1))->action(0x13);
                        FloatModule* fm = *(FloatModule**)((char*)(*(void**)((char*)accesser + 0xd8)) + 0x1c);
                        Target** t = list->get(1);
                        float fl = fm->getFloat();
                        fn_113_24D8C(manager, *t, fl);
                    }
                    break;
                }
                }
                float fl2 = (*(FloatModule**)((char*)(*(void**)((char*)accesser + 0xd8)) + 0x1c))->getFloat();
                fn_113_24D8C(manager, fn_113_244FC(manager), fl2);
                fn_113_10DD0(*(void**)((char*)accesser + 8));
            }
        }
    }
}
