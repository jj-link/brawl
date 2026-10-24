#pragma force_active on

struct Vec3 {
    float x, y, z;
    Vec3(const Vec3& o) : x(o.x), y(o.y), z(o.z) {}
};

struct Pos {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual Vec3 get();
    virtual void set(const Vec3&);
};

struct Work {
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
    virtual void setFlag(float, unsigned int);
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void setObj(unsigned int, void*);
};

struct Status {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void change(unsigned int, void*);
};

struct Modules {
    char pad0[0xC];
    Pos* pos;
    char pad1[0x54];
    Work* work;
    char pad2[0x8];
    Status* status;
};

struct Context {
    char pad[0xD8];
    Modules* modules;
};

struct Cmd {
    int type;
    int pad;
    float x;
    float y;
    float z;
    float f14;
    float f18;
};

extern "C" void fn_27_174B48(void*, Cmd*, Context*);

extern "C" void fn_27_17814C(void* self, Cmd* cmd, Context* ctx) {
    int type = cmd->type;
    if (type <= 0x16 || type >= 0x1a) {
        fn_27_174B48(self, cmd, ctx);
        return;
    }

    switch (type) {
    case 0x18:
        ctx->modules->work->setFlag(cmd->f14, 0x21000004);
        ctx->modules->work->setFlag(cmd->f18, 0x21000005);
        ctx->modules->work->setObj(0x2200000C, ctx->modules);
        ctx->modules->status->change(0xC4, ctx);
        break;

    case 0x19: {
        Vec3 v = ctx->modules->pos->get();
        v.x = cmd->x;
        v.y = cmd->y;
        ctx->modules->pos->set(v);
        break;
    }
    }
}
