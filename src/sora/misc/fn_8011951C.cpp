#pragma force_active on

class gfTask;

extern "C" {
gfTask* fn_80111E78(void* p);
int fn_80134344(void* p, unsigned int idx);
}

struct gfTask_base { char pad[0x3c]; };

class gfTask : public gfTask_base {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void processPreCollision();
    virtual void processCollision();
    virtual void processCatch();
    virtual void processHit();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void processGameProc();
    virtual void processEnd();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual void slot21();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void slot25();
    virtual void slot26();
    virtual void slot27();
    virtual void slot28();
    virtual void slot29();
    virtual void slot30(int a, void* b, void* c);
};

struct Ctx { char pad[0x75]; unsigned char flags75; };
struct Mid { char pad[0x58]; gfTask* f58; };
struct Handle {
    unsigned int a;
    Mid* b;
    unsigned int c;
    char pad[0xc];
    bool isValid() {
        bool r = false;
        if (a != 0 && b != 0 && c != 0) {
            r = true;
        }
        return r;
    }
};
struct Outer {
    char pad0[0x18];
    Ctx* ctx18;
    char pad1c[0x20];
    Handle h3c;
    Handle h54;
    Handle h6c;
    Handle h84;
};

inline bool getTask(Handle* h, unsigned int& obj, Mid*& mid) {
    bool found = false;
    if (h->isValid()) {
        Mid* m = h->b;
        gfTask* t = m->f58;
        if (t != 0) {
            obj = (unsigned int)t;
            mid = m;
            found = true;
        }
    }
    return found;
}

extern "C" void fn_8011951C(Outer* arg0, int arg1, Handle* arg2) {
    gfTask* q;
    Mid* mid;
    unsigned int flag = 0;
#define obj flag

    if ((arg0->ctx18->flags75 >> 7) & 1) {
        Handle* h = &arg0->h84;
        if (h->isValid()) {
            mid = h->b;
            gfTask* p = fn_80111E78(h);
            if (p != 0) {
                if (arg1 == 2) {
                    flag = 1;
                } else if (arg1 == 1) {
                    if (!arg2->isValid()) {
                        flag = 1;
                    } else {
                        q = fn_80111E78(arg2);
                        if (q != p) {
                            flag = 1;
                        }
                    }
                }
                p->slot30(flag != 0, arg0->ctx18, mid);
            }
        }
    }

    flag = 0;
    mid = 0;
    if ((arg0->ctx18->flags75 >> 6) & 1) {
        if (getTask(&arg0->h3c, flag, mid)) {
            ((gfTask*)flag)->slot30(2, arg0->ctx18, mid);
        }
    }

    if (fn_80134344(arg0->ctx18, 1) != 0) {
        if (getTask(&arg0->h54, flag, mid)) {
            ((gfTask*)flag)->slot30(3, arg0->ctx18, mid);
        }
    }

    if (fn_80134344(arg0->ctx18, 2) != 0) {
        if (getTask(&arg0->h6c, flag, mid)) {
            ((gfTask*)flag)->slot30(4, arg0->ctx18, mid);
        }
    }
}
