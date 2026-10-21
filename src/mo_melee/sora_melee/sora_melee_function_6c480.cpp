#include <types.h>
#pragma force_active on

struct SubObj {
    u8 pad[0x3C];
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
    virtual void target(u32, u32);
};

extern "C" void* getNode__6utListFUl(void*, u32);
extern "C" void* fn_27_6F30C(void*);

extern "C" void fn_27_6C480(void* self, u32 a, u32 b) {
    u8* node = (u8*)getNode__6utListFUl((u8*)self + 0x14, 0);
    while (node != nullptr) {
        u8* obj = *(u8**)(node + 0xC);
        if ((*(u32*)(obj + 0x30) >> 8) & 0x1000) {
            u8* acc = (u8*)fn_27_6F30C(node);
            u8* inner = *(u8**)(acc + 0x44);
            SubObj* o = *(SubObj**)(inner + 0x8);
            o->target(a, b);
        }
        node = *(u8**)node;
    }
}
