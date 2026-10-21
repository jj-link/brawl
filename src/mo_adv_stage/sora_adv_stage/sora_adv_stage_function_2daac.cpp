#pragma force_active on

extern "C" {
    void fn_27_25F8B8(void*, void*, int);
    void remove__11gfSceneRootFPQ34nw4r3g3d6ScnMdl(void*, void*);
    extern void* g_gfSceneRoot;
}

class Base {
    char pad[0x3C];

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
    virtual void proc(unsigned int);
};

struct Self {
    char _00[0x44];
    void** _44;
    char _48[0x10C];
    int _154;
};

extern "C" void fn_40_2DAAC(Self* self, unsigned int layer) {
    if (layer == 1) {
        fn_27_25F8B8(self, self->_44[self->_154], 0);
    } else {
        remove__11gfSceneRootFPQ34nw4r3g3d6ScnMdl(
            g_gfSceneRoot, self->_44[self->_154]);
    }
    reinterpret_cast<Base*>(self)->proc(layer);
}
