#pragma force_active on

struct Command {
    int type;
    int pad;
    float x;
    float y;
    float z;
    float a;
    float b;
};

struct Vec3 {
    float x, y, z;
    Vec3(const Vec3& o) : x(o.x), y(o.y), z(o.z) {}
};

struct Pos {
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual Vec3 get();
    virtual void set(const Vec3&);
    virtual void s6();
    virtual void s7();
    virtual void s8();
    virtual float getF();
    virtual void setF(float);
    virtual void s11();
    virtual void s12();
    virtual void s13();
    virtual void s14();
    virtual void s15();
    virtual void s16();
    virtual void s17();
    virtual void s18();
    virtual void upd();
};

struct Work {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual int getInt(unsigned int);
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
    virtual void sendMsg(unsigned int);
};

struct Modules {
    char pad[0xC];
    Pos* pos;
    char pad2[0x54];
    Work* work;
};

struct Ctx {
    char pad[0xD8];
    Modules* m;
};

struct ftManager {
    char pad[0x68];
    unsigned char f;
};

extern "C" {
void fn_27_174B48(void*, Command*, Ctx*);
void fn_27_6155C(float, float);
int fn_27_1125B0();
void* getOwner__9ftManagerFi(ftManager*, int);
void* __dynamic_cast(void*, long, const void*, const void*, short);
extern ftManager* g_ftManager;
extern char lbl_27_data_70F8[];
extern char lbl_27_data_6898[];
}

extern "C" void fn_27_1769F4(void* self, Command* cmd, Ctx* ctx) {
    int t = cmd->type;
    if (t <= 0xb || t >= 0xf) {
        fn_27_174B48(self, cmd, ctx);
        return;
    }
    switch (t) {
    case 0xd: {
        __dynamic_cast(*(void**)((char*)ctx->m + 0x38), 8, lbl_27_data_70F8, lbl_27_data_6898, 1);
        fn_27_6155C(cmd->b, cmd->a);
        ftManager* fm = g_ftManager;
        if (fm->f == 1) {
            int id = ctx->m->work->getInt(0x10000000);
            getOwner__9ftManagerFi(fm, id);
            if (fn_27_1125B0() == 1) {
                ctx->m->work->sendMsg(0x12000034);
            }
        }
        break;
    }
    case 0xe: {
        Vec3 v = ctx->m->pos->get();
        v.x = cmd->x;
        v.y = cmd->y;
        ctx->m->pos->set(v);
        if (cmd->z != ctx->m->pos->getF()) {
            ctx->m->pos->setF(cmd->z);
            ctx->m->pos->upd();
        }
        break;
    }
    }
}
