#pragma force_active on

extern "C" {
extern const char lbl_113_data_61C[];
extern const char lbl_113_data_2950[];
void* __dynamic_cast(void*, long, const void*, const void*, short);
int fn_113_243CC(void*);
void* fn_113_244FC(void*);
void fn_113_24D8C(void*, void*, float);
}

class Callback {
public:
    virtual void v0();
    virtual void invoke();
};

extern "C" Callback lbl_27_bss_4964;

inline void invokeCallback(Callback* callback) {
    callback->invoke();
}

class Target;

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

extern "C" TargetList* fn_113_24550(void*);

extern "C" void fn_113_11050(void* arg1, void* arg2) {
    invokeCallback(&lbl_27_bss_4964);

    void* target = __dynamic_cast(
        *(void**)((char*)arg2 + 8), 0x3c,
        lbl_113_data_61C, lbl_113_data_2950, short(0));

    if (target) {
        void* manager = (char*)target + 0x1fd08;
        if (fn_113_243CC(manager) > 0) {
            float fl = (*(FloatModule**)((char*)(*(void**)((char*)arg2 + 0xd8)) + 0x1c))->getFloat();
            fn_113_24D8C(manager, fn_113_244FC(manager), fl);

            TargetList* list = fn_113_24550(manager);
            if (list->size() > 1) {
                FloatModule* fm = *(FloatModule**)((char*)(*(void**)((char*)arg2 + 0xd8)) + 0x1c);
                Target** t = list->get(1);
                fn_113_24D8C(manager, *t, fm->getFloat());
            }

            float fl3 = (*(FloatModule**)((char*)(*(void**)((char*)arg2 + 0xd8)) + 0x1c))->getFloat();
            fn_113_24D8C(manager, fn_113_244FC(manager), fl3);
        }
    }
}