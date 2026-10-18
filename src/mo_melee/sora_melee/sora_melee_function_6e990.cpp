#include <types.h>
#pragma force_active on

class utList {
public:
    void* getNode(u32 index);
};

extern "C" u32 fn_27_6F30C(void* self);

struct VHdr {
    u32 m0;
    u32 m1;
};

class VBase : public VHdr {
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
    virtual u32 vfn70(float f, u32 x);
};

extern "C" bool fn_27_6E990(void* self, float f) {
    utList* list = (utList*)((char*)self + 0x14);
    void* node = list->getNode(0);
    while (node != 0) {
        void* obj = *(void**)((char*)node + 0xc);
        if (((*(u32*)((char*)obj + 0x30)) >> 8) & 0x8000) {
            VBase* c = (VBase*)*(void**)((char*)*(void**)((char*)*(void**)((char*)fn_27_6F30C(node) + 0x44) + 0xd8) + 0x10);
            if (c->vfn70(f, 0) == 1) {
                return true;
            }
        }
        node = *(void**)node;
    }
    return false;
}
