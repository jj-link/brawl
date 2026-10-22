#pragma force_active on

class Base {
public:
    unsigned int a;
    unsigned int b;
};

struct Big {
    unsigned int x;
    unsigned int y;
    Big() {}
    Big(const Big& o) : x(o.x), y(o.y) {}
};

class Obj : public Base {
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
    virtual void v16(void*, void*, void*, void*, void*, void*);
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
    virtual void* v35(void*);
    virtual void v36();
    virtual void v37();
    virtual Big v38(void*, int);
};

extern "C" void fn_27_5EA98(void* self, void* arg1, void* arg2, void* arg3, void* arg4, void* arg5, void* arg6) {
    unsigned char* holder = *(unsigned char**)((unsigned char*)self + 0x3c);
    Obj* obj = *(Obj**)(*(unsigned char**)(holder + 0xd8) + 4);
    void* ret = obj->v35(arg2);
    unsigned char* holder2 = *(unsigned char**)((unsigned char*)self + 0x3c);
    Obj* obj2 = *(Obj**)(*(unsigned char**)(holder2 + 0xd8) + 4);
    Big sp8 = obj2->v38(ret, 0);
    ((Obj*)self)->v16(arg1, &sp8, arg3, arg4, arg5, arg6);
}
