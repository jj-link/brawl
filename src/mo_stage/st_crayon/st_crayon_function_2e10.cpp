#pragma force_active on

struct CrayonBase {
    unsigned char padding[0x3C];
};

class grCrayonYakumonoH : public CrayonBase {
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
    virtual void initialize();
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
    virtual void setId(int);

    static grCrayonYakumonoH* create(int, const char*);
};

extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
extern "C" grCrayonYakumonoH* fn_56_2EA8(grCrayonYakumonoH*, const char*);

grCrayonYakumonoH* grCrayonYakumonoH::create(int id, const char* name) {
    grCrayonYakumonoH* object =
        (grCrayonYakumonoH*)__nw__FUlQ25Heaps8HeapType(0x1C4, 15);

    if (object) {
        object = fn_56_2EA8(object, name);
    }

    if (object) {
        object->setId(id);
    }

    object->initialize();
    return object;
}
