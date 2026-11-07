#include <types.h>
#pragma force_active on

extern "C" {
int getEntryId__9ftManagerFi(void* self, int a);
void* getOwner__9ftManagerFi(void* self, int id);
void fn_40_18BCC(void*);
void fn_40_17CC8(void*);
void* fn_40_47E50(void*);
void* fn_80158BE0();
void fn_8015982C();
void fn_1_324C8();
}
extern void* g_ftManager;
extern char* g_gfApplication;
extern float lbl_40_rodata_25C;

struct Desc {
    int a;
    int b;
    int c;
    int d;
    int e;
    int f;
    void* g;
};
extern Desc lbl_40_data_37A0;

class Owner {
public:
    char pad[0xc];
    virtual void v0();
    virtual void v1();
    virtual void set10(int, float);
    virtual void v3();
    virtual void set18(float);
};

struct Self {
    char _0[0x44];
    char* m_44;
    void* m_48;
    char _4c[0x54 - 0x4c];
    char m_54[0xc1 - 0x54];
    u8 m_c1;
    char _c2[0xcc - 0xc2];
    u32 m_cc;
    char _d0;
    u8 m_d1;
};

extern "C" void fn_40_175C0(Self* self) {
    if (*(u8*)(self->m_44 + 0x603) != 7) {
        self->m_cc = 0;
        return;
    }
    if (self->m_c1 != 0) return;
    if ((*(u32*)(g_gfApplication + 0xec) >> 27) != 0) {
        self->m_cc = 0;
        return;
    }
    if (++self->m_cc < 10) return;
    if (self->m_48 == 0) {
        for (int i = 0; i < 2; i++) {
            int id = getEntryId__9ftManagerFi(g_ftManager, i);
            if (id != -1) {
                Owner* o = (Owner*)getOwner__9ftManagerFi(g_ftManager, id);
                o->set18(lbl_40_rodata_25C);
                o->set10(0, lbl_40_rodata_25C);
            }
        }
        self->m_d1 = 0;
        fn_40_18BCC(self);
        char* p = self->m_44;
        int v;
        if ((*(u8*)(p + 0x606) >> 7) & 1) {
            v = *(int*)(p + 0x4934);
        } else {
            v = -1;
        }
        Desc d = lbl_40_data_37A0;
        int b = *(s8*)(self->m_44 + 0x5fb);
        ((u8*)&d)[0x0a] = 0;
        d.b = b;
        d.d = *(int*)(self->m_44 + 0x492c);
        d.e = v;
        d.g = self->m_54;
        self->m_48 = fn_40_47E50(&d);
        fn_80158BE0();
        fn_8015982C();
        fn_1_324C8();
    } else {
        fn_40_17CC8(self);
    }
}
