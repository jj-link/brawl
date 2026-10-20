#pragma force_active on
typedef unsigned int u32;
typedef unsigned char u8;

extern "C" void* getNode__6utListFUl(void*, u32);
extern "C" void* fn_27_6F30C(void*);
extern "C" u8 g_soControllerNull[];

class VBase {
public:
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual int isCheck(int);
};

class VCtrl {
public:
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
    virtual void* getCtrl2();
};

extern "C" void* fn_27_6C24C(void* self) {
    VBase* b = (VBase*)self;
    u8* p = (u8*)self;
    if (b->isCheck(-1)) {
        u8* node = (u8*)getNode__6utListFUl(p + 0x20, 0);
        while (node) {
            u8* data = *(u8**)(node + 0xc);
            if (((*(u32*)(data + 0x30)) >> 8) & 0x10) {
                u8* acc = (u8*)fn_27_6F30C(node);
                u8* obj = *(u8**)(acc + 0x44);
                u8* sub = *(u8**)(obj + 0xd8);
                VCtrl* ctrl = *(VCtrl**)(sub + 0x5c);
                return ctrl->getCtrl2();
            }
            node = *(u8**)node;
        }
    }
    return g_soControllerNull;
}
