#pragma force_active on

extern "C" {
void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
void __ct__10grYakumonoFPCc(void*, const char*);
extern unsigned char lbl_74_data_8B0[];
extern unsigned char lbl_74_data_678[];
extern const float lbl_74_rodata_90;
}

struct Base {
    unsigned char pad[0x3c];
};

struct Node {
    Node* next;
    Node* prev;

    Node* init() {
        next = 0;
        prev = 0;
        return this;
    }

    void link(Node* n) {
        next = n;
        prev = n;
    }
};

struct Object : Base {
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
    virtual void v42(int);
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
    virtual void v78(const char*);

    unsigned char pad1[0x110];
    unsigned char state;
    unsigned char pad2[3];
    float frame;
    unsigned int field158;
    unsigned int field15C;
    unsigned int field160;
    unsigned int field164;
    Node node;
};

extern "C" Object* fn_74_2708(int model, const char* node, const char* name) {
    Object* p = (Object*)__nw__FUlQ25Heaps8HeapType(0x170, 15);
    if (p) {
        __ct__10grYakumonoFPCc(p, name);
        *(void**)((char*)p + 0x3c) = lbl_74_data_8B0;
        p->state = 0;
        p->frame = lbl_74_rodata_90;
        p->v26();
        *(void**)((char*)p + 0x3c) = lbl_74_data_678;
        Node* n = p->node.init();
        p->field164 = 0;
        n->link(&p->node);
        p->field158 = 0;
        p->field15C = 0;
        p->field160 = 0;
    }
    if (p) {
        p->v42(model);
        p->v78(node);
    }
    return p;
}
