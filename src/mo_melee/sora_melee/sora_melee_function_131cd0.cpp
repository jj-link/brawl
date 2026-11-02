#pragma force_active on
typedef unsigned int u32;

struct Vec3 {
    float x, y, z;
};

struct Work {
    virtual void dummy0();
    virtual void dummy1();
    virtual void dummy2();
    virtual void dummy3();
    virtual void dummy4();
    virtual void setInt(int, u32);
    virtual void dummy6();
    virtual void dummy7();
    virtual void dummy8();
    virtual void dummy9();
    virtual void dummy10();
    virtual void dummy11();
    virtual float getFloat(u32);
    virtual void setFloat(float, u32);
    virtual void dummy14();
    virtual void dummy15();
    virtual void dummy16();
    virtual void dummy17();
    virtual void dummy18();
    virtual void offFlag(u32);
};

struct Status {
    virtual void dummy0();
    virtual void dummy1();
    virtual void dummy2();
    virtual void dummy3();
    virtual void dummy4();
    virtual void dummy5();
    virtual void dummy6();
    virtual void dummy7();
    virtual void dummy8();
    virtual void dummy9();
    virtual void dummy10();
    virtual void dummy11();
    virtual void dummy12();
    virtual void dummy13();
    virtual void dummy14();
    virtual void dummy15();
    virtual u32 getStatusKind();
};

struct Posture {
    virtual void dummy0();
    virtual void dummy1();
    virtual void dummy2();
    virtual void dummy3();
    virtual Vec3 getPos();
};

struct Modules {
    char pad0[0xc];
    Posture* posture;
    char pad10[0x54];
    Work* work;
    char pad68[8];
    Status* status;
};

struct Accessor {
    char pad[0xd8];
    Modules* modules;
};

struct Pad {
    char bytes[0x3c];
};

struct Object : Pad {
    virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3(); virtual void d4();
    virtual void d5(); virtual void d6(); virtual void d7(); virtual void d8(); virtual void d9();
    virtual void d10(); virtual void d11(); virtual void d12(); virtual void d13(); virtual void d14();
    virtual void d15(); virtual void d16(); virtual void d17(); virtual void d18(); virtual void d19();
    virtual void d20(); virtual void d21(); virtual void d22(); virtual void d23(); virtual void d24();
    virtual void d25(); virtual void d26(); virtual void d27(); virtual void d28(); virtual void d29();
    virtual void d30(); virtual void d31(); virtual void d32(); virtual void d33(); virtual void d34();
    virtual void d35(); virtual void d36(); virtual void d37(); virtual void d38(); virtual void d39();
    virtual void d40(); virtual void d41(); virtual void d42(); virtual void d43(); virtual void d44();
    virtual void d45(); virtual void d46(); virtual void d47(); virtual void d48(); virtual void d49();
    virtual void d50(); virtual void d51(); virtual void d52(); virtual void d53(); virtual void d54();
    virtual void d55(); virtual void d56(); virtual void d57(); virtual void d58(); virtual void d59();
    virtual void d60(); virtual void d61(); virtual void d62(); virtual void d63(); virtual void d64();
    virtual void d65(); virtual void d66(); virtual void d67(); virtual void d68(); virtual void d69();
    virtual void d70(); virtual void d71(); virtual void d72(); virtual void d73(); virtual void d74();
    virtual void d75(); virtual void d76(); virtual void d77(); virtual void d78(); virtual void d79();
    virtual void d80(); virtual void d81(); virtual void d82(); virtual void d83(); virtual void d84();
    virtual void d85(); virtual void d86(); virtual void d87(); virtual void d88(); virtual void d89();
    virtual void d90(); virtual void d91(); virtual void d92(); virtual void d93(); virtual void d94();
    virtual void d95(); virtual void d96(); virtual void d97(); virtual void d98(); virtual void d99();
    virtual void d100(); virtual void d101(); virtual void d102(); virtual void d103(); virtual void d104();
    virtual void d105(); virtual void d106(); virtual void d107(); virtual void d108(); virtual void d109();
    virtual void d110(); virtual void d111(); virtual void d112(); virtual void d113(); virtual void d114();
    virtual void d115(); virtual void d116(); virtual void d117(); virtual void d118(); virtual void d119();
    virtual void d120(); virtual void d121(); virtual void d122(); virtual void d123(); virtual void d124();
    virtual void d125(); virtual void d126(); virtual void d127(); virtual void d128(); virtual void d129();
    virtual void d130(); virtual void d131(); virtual void d132(); virtual void d133(); virtual void d134();
    virtual void d135(); virtual void d136(); virtual void d137(); virtual void d138(); virtual void d139();
    virtual void d140(); virtual void d141(); virtual void d142(); virtual void d143(); virtual void d144();
    virtual void d145(); virtual void d146(); virtual void d147(); virtual void d148(); virtual void d149();
    virtual void d150(); virtual void d151(); virtual void d152(); virtual void d153(); virtual void d154();
    virtual void d155(); virtual void d156(); virtual void d157(); virtual void d158(); virtual void d159();
    virtual void d160(); virtual void d161(); virtual void d162(); virtual void d163(); virtual void d164();
    virtual void d165(); virtual void d166(); virtual void d167(); virtual void d168(); virtual void d169();
    virtual void d170(); virtual void d171(); virtual void d172(); virtual void d173(); virtual void d174();
    virtual void d175(); virtual void d176(); virtual void d177(); virtual void d178(); virtual void d179();
    virtual void d180(); virtual void d181(); virtual void d182(); virtual void d183(); virtual void d184();
    virtual void* getState();
    virtual u32 getKind();
    char pad40[0x20];
    Accessor* accessor;
    char pad64[0xa8];
    int id;
};

struct Audience {
    virtual void dummy0();
    virtual void dummy1();
    virtual void dummy2();
    virtual void dummy3();
    virtual void dummy4();
    virtual void dummy5();
    virtual void dummy6();
    virtual void dummy7();
    virtual void notify(int, float, float);
};

struct AudienceManager {
    char pad[8];
    Audience* audience;
};

extern "C" {
extern unsigned char g_ftCommonDataAccesser;
extern AudienceManager* g_ftAudienceManager;
extern const float lbl_27_rodata_1048;
u32* fn_27_14554C(void*, u32, u32);
void fn_27_1D7104(void*, u32);
}

#define SET_INT(a, v, k) ((a)->modules->work->setInt((v), (k)))
#define SET_FLOAT(a, v, k) ((a)->modules->work->setFloat((v), (k)))
#define OFF_FLAG(a, k) ((a)->modules->work->offFlag((k)))

extern "C" void fn_27_131CD0(Object* self, int kind, u32 st, Accessor* accessor) {
    u32 notify;
    u32 special = 0;

    if (kind == 2) {
        special = 1;
    } else {
        st = accessor->modules->status->getStatusKind();
        u32* data = fn_27_14554C(&g_ftCommonDataAccesser, self->getKind(), st);
        void* state = self->getState();

        notify = (u32)kind <= 6 && ((1 << kind) & 0x43) && !((*data >> 3) & 1);

        SET_INT(accessor, 0, 0x10000003);
        SET_INT(accessor, 0, 0x10000004);
        SET_FLOAT(accessor, lbl_27_rodata_1048, 0x11000002);
        SET_INT(accessor, 0, 0x1000000c);
        SET_INT(accessor, 0, 0x1000000b);
        SET_INT(accessor, 0, 0x10000005);
        SET_INT(accessor, 0, 0x10000039);
        SET_INT(accessor, 0, 0x1000003b);
        OFF_FLAG(accessor, 0x1200000d);
        OFF_FLAG(accessor, 0x12000016);
        OFF_FLAG(accessor, 0x12000011);

        if (notify == 1) {
            Accessor* own = self->accessor;
            SET_INT(own, 0, 0x10000038);
            SET_INT(own, 0, 0x1000002c);
            SET_FLOAT(own, lbl_27_rodata_1048, 0x1100000d);
            SET_INT(own, 0, 0x1000003d);

            Posture* posture = accessor->modules->posture;
            int id = self->id;
            Audience* audience = g_ftAudienceManager->audience;
            float value = accessor->modules->work->getFloat(0x1100000e);
            audience->notify(id, posture->getPos().x, value);

            SET_FLOAT(accessor, lbl_27_rodata_1048, 0x1100000e);
            SET_INT(accessor, 0, 0x10000013);
            SET_INT(accessor, 0, 0x10000014);
        }

        if (kind != 1) {
            SET_INT(accessor, 0, 0x1000003e);
        }

        fn_27_1D7104(state, notify);
    }

    SET_INT(accessor, special, 0x10000001);
}
