#pragma force_active on

struct Big {
    unsigned int x;
    unsigned int y;
    Big() {}
    Big(const Big& o) : x(o.x), y(o.y) {}
};

struct S {
    unsigned int a;
    unsigned int b;
};

class Obj : public S {
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
    virtual void* v33(void*);
    virtual void v34();
    virtual void v35();
    virtual Big v36(void*, int);
};

class Self {
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
    virtual void v10(void*, void*, void*, void*, void*);
};

extern "C" void fn_27_3B070(void* self, void* arg1, void* arg2, void* arg3, void* arg4, void* arg5) {
    Obj* obj = *(Obj**)(*(unsigned char**)(*(unsigned char**)((unsigned char*)self + 0x28) + 0xd8) + 4);
    void* res = obj->v33(arg2);
    unsigned char* owner = *(unsigned char**)((unsigned char*)self + 0x28);
    Obj* obj2 = *(Obj**)(*(unsigned char**)(owner + 0xd8) + 4);
    Big sp8 = obj2->v36(res, 0);
    ((Self*)self)->v10(arg1, &sp8, arg3, arg4, arg5);
}
