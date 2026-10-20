#pragma force_active on

extern "C" {
void fn_27_169554(void);
int fn_113_243CC(void*);
void* fn_113_244FC(void*);
void fn_113_24D8C(void*, void*, float);
}

class SomeClass {
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
    virtual float v44();
};

extern "C" void fn_113_12FE8(void* arg1, void* arg2) {
    fn_27_169554();
    if (fn_113_243CC(*(void**)((char*)arg1 + 4)) > 0) {
        void* manager = *(void**)((char*)arg1 + 4);
        SomeClass* obj = *(SomeClass**)((char*)(*(void**)((char*)arg2 + 0xd8)) + 0x1c);
        float fl = obj->v44();
        void* target = fn_113_244FC(manager);
        fn_113_24D8C(manager, target, fl);
    }
}
