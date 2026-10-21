#pragma force_active on
class Obj {
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
    virtual int v16(int);
    virtual void v17();
    virtual int v18(int);
    virtual int v19(int);
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
    virtual void v43(int, int);
};

extern "C" {
extern char lbl_27_data_17780[];
extern char lbl_27_data_9E50[];
void* __dynamic_cast(void*, long, const void*, const void*, short);
}

extern "C" void fn_27_357A08(void* self, void* accesser) {
    char* p = *(char**)((char*)accesser + 0xD8);
    Obj* first = *(Obj**)(p + 0x64);
    Obj* second = (Obj*)__dynamic_cast(*(void**)(p + 0xA8), 0, lbl_27_data_17780, lbl_27_data_9E50, 1);
    if (first->v19(0x22000012)) {
        for (int i = 3; i < 7; i++) {
            if (second->v16(i)) {
                second->v43(0, i);
            }
        }
    }
}
