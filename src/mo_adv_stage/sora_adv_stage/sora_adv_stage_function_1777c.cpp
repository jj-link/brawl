#include <types.h>
#include <gf/gf_camera.h>
#include <gf/gf_resource_loader.h>
#include <mu/adv/mu_adv_seal.h>
#include <ad/ad_autosave.h>
#pragma force_active on


extern "C" {
void fn_27_10A1AC(void*, int);
void fn_40_17F44(void*);
void fn_40_1FF8(void*, u32);
void* fn_40_47E50(void*);
void fn_40_18BCC(void*);
void fn_40_5E74(void*, void*);
void fn_8000E590(void*, int, int);
void fn_80158BE0();
void fn_8015982C();
void fn_1_324C8();
void fn_80159420();
void fn_8015A358();
int fn_8015A33C();
void* fn_80107E74(void*);
int isAlive__10adAutoSaveFv(void*);
void* create__10adAutoSaveFb(int);
void exit__6gfTaskFv(void*);
void endKeepScreen__17gfKeepFrameBufferFv(void*);
void* getManager__15gfCameraManagerFv(void*);
void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
void* __ct__9gfArchiveFv(void*);
void __dt__9gfArchiveFv(void*, short);
void __dt__14gfFileIOHandleFv(void*, short);
void __dl__FPv(void*);
int isLoaded__16gfResourceLoaderFv(void*);
void freeResource__16gfResourceLoaderFv(void*);
void getResourcePackData__13muAdvSealTaskFPPCcPUl(const char**, u32*);
void loadResourceMemSizeOrder__16gfResourceLoaderFQ25Heaps8HeapTypePCcP9gfArchiveUl(void*, int, const char*, void*, u32);
void* create__13muAdvSealTaskFPC18muAdvSealTaskParamP9gfArchive(void*, void*);
}

extern void* g_ftManager;
extern char* g_gfApplication;
extern void* g_gfSceneRoot;
extern char* g_IfAdvMngr;
extern char* g_GameGlobal;
extern float lbl_27_data_547E0;
extern void* lbl_40_bss_15C;
extern float lbl_40_data_379C;

struct Rodata230 {
    char pad0[0x2C];
    float f2C;
    float f30;
    float f34;
    float f38;
};
extern const Rodata230 lbl_40_rodata_230;

struct Desc {
    int a, b, c, d, e, f;
    void* g;
};
extern Desc lbl_40_data_37A0;

struct Loader {
    u32 f0, f4, f8, fC, f10, f14, f18;
    u8 f1C;
};

struct Param {
    u32 a;
    int b;
};

class Object_vptr_3c_base { public: char pad[0x3c]; };
class Object_vptr_3c : public Object_vptr_3c_base {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
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
    virtual void slot30();
    virtual void slot31();
    virtual void slot32();
    virtual void slot33();
    virtual void slot34();
    virtual void slot35();
    virtual void slot36();
    virtual void slot37();
    virtual void slot38();
    virtual void slot39();
    virtual void slot40();
    virtual void slot41();
    virtual void slot42();
    virtual void slot43();
    virtual void slot44();
    virtual void slot45();
    virtual void slot46();
    virtual void slot47();
    virtual void slot48();
    virtual void slot49();
    virtual void slot50();
    virtual void slot51();
    virtual void slot52();
};

struct Flag4924 { u8 pad : 4; u8 save : 1; };
struct IfAdvMngr {
    char pad0[0x118];
    u8 unk118;
};

struct Self {
    char _0[0x44];
    char* m_44;
    void* m_48;
    void* m_4c;
    void* m_50;
    char m_54[0xC0 - 0x54];
    u8 m_c0;
    u8 m_c1;
    char _c2[0xC4 - 0xC2];
    float m_c4;
    u32 m_c8;
    char _cc[0xD0 - 0xCC];
    u8 m_d0;
    u8 m_d1;
    u8 m_d2;
    char _d3[0xD4 - 0xD3];
    float m_d4;
    float m_d8;
    void* m_dc;
    void* m_e0;
};

extern "C" void fn_40_1777C(Self* self) {
    const Rodata230* rd = &lbl_40_rodata_230;

    if (self->m_d1 != self->m_d2) {
        if (lbl_40_data_379C > rd->f2C && self->m_d1 == 1) {
            lbl_40_data_379C -= rd->f30;
        } else {
            fn_27_10A1AC(g_ftManager, self->m_d1);
            lbl_40_data_379C = (self->m_d2 = self->m_d1, rd->f34);
        }
    }

    if (self->m_d0 != 0) {
        fn_40_17F44(self);
    }

    switch (self->m_c0) {
    case 1:
        float threshold, time, delta;
        time = self->m_c4;
        delta = lbl_27_data_547E0;
        threshold = rd->f38;
        time += delta;
        self->m_c4 = time;
        if (time > threshold) {
            self->m_c0 = 2;
        }
        break;
    case 2:
        fn_40_1FF8(lbl_40_bss_15C, self->m_c8);
        self->m_c0 = 3;
        break;
    }

    if (*(u8*)(self->m_44 + 0x603) == 7 && (*(u32*)(g_gfApplication + 0xEC) >> 27) == 0) {
        if (self->m_c1 == 0) {
            char* s48 = (char*)self->m_48;
            if (s48 != 0 && *(int*)(s48 + 0x4C) == 7) {
                self->m_d0 = 1;
            }
            return;
        }

        switch (self->m_c1) {
        case 1: {
            void* a = __nw__FUlQ25Heaps8HeapType(0x80, 0x2B);
            if (a != 0) {
                a = __ct__9gfArchiveFv(a);
            }
            self->m_dc = a;
            gfResourceLoader* l = new (Heaps::MenuResource) gfResourceLoader;
            self->m_e0 = l;
            const char* path;
            u32 size;
            getResourcePackData__13muAdvSealTaskFPPCcPUl(&path, &size);
            loadResourceMemSizeOrder__16gfResourceLoaderFQ25Heaps8HeapTypePCcP9gfArchiveUl(
                self->m_e0, 0x2B, path, self->m_dc, size);
            self->m_c1 = 2;
            return;
        }
        case 2: {
            if (isLoaded__16gfResourceLoaderFv(self->m_e0) != 0) {
                struct UnkParam { union { bool asBool; u32 asInt; } unk0; u32 unk4; };
                Param p = {};
                Vec2f pos;
                UnkParam stack10;
                UnkParam stack18;
                UnkParam stack20;
                char* gg = *(char**)(g_GameGlobal + 0x30);
                if (gg != 0) {
                    stack18.unk0.asInt = *(u32*)(gg + 0x4928);
                    stack18.unk4 = *(u32*)(gg + 0x492C);
                } else {
                    stack10.unk0.asBool = false;
                    stack10.unk4 = -1;
                    stack18 = stack10;
                }
                stack20 = stack18;
                p.b = stack20.unk4;
                self->m_4c = create__13muAdvSealTaskFPC18muAdvSealTaskParamP9gfArchive(&p, self->m_dc);
                char* m44 = self->m_44;
                ((Flag4924*)(m44 + 0x4924))->save = 0;
                fn_8000E590(g_gfSceneRoot, 8, 1);
                self->m_c1 = 3;
                ((IfAdvMngr*)g_IfAdvMngr)->unk118 = 0;
                Vec3f camv;
                camv = gfCameraManager::getManager()->m_cameras[0].m_targetPos;
                pos = *camv.xy();
                self->m_d4 = pos.m_x;
                self->m_d8 = pos.m_y;
                return;
            }
            break;
        }
        case 3: {
            void* t = self->m_4c;
            if (t != 0 && *(int*)((char*)t + 0x40) != 0) {
                exit__6gfTaskFv(t);
                char* p44 = self->m_44;
                self->m_4c = 0;
                if ((p44[0x4924] >> 3) & 1) {
                    self->m_c1 = 4;
                    ((Flag4924*)(p44 + 0x4924))->save = 0;
                    self->m_50 = create__10adAutoSaveFb(0);
                } else {
                    self->m_c1 = 5;
                }
                if (self->m_dc != 0) {
                    __dt__9gfArchiveFv(self->m_dc, 1);
                    self->m_dc = 0;
                }
                gfResourceLoader* l = (gfResourceLoader*)self->m_e0;
                if (l != 0) {
                    delete l;
                    self->m_e0 = 0;
                }
                fn_8000E590(g_gfSceneRoot, 8, 0);
                ((IfAdvMngr*)g_IfAdvMngr)->unk118 = 1;
                endKeepScreen__17gfKeepFrameBufferFv(g_gfApplication + 0xD0);
                fn_40_18BCC(self);
                char* p44b = self->m_44;
                int v;
                if ((p44b[0x606] >> 7) & 1) {
                    v = *(int*)(p44b + 0x4934);
                } else {
                    v = -1;
                }
                Desc d = lbl_40_data_37A0;
                int b = *(s8*)(self->m_44 + 0x5FB);
                ((u8*)&d)[0x0A] = 1;
                d.b = b;
                d.d = *(int*)(self->m_44 + 0x492C);
                d.e = v;
                d.g = self->m_54;
                self->m_48 = fn_40_47E50(&d);
                fn_80158BE0();
                fn_8015982C();
                fn_1_324C8();
                ((Object_vptr_3c*)lbl_40_bss_15C)->slot52();
                fn_40_5E74(lbl_40_bss_15C, (char*)self + 0xD4);
                return;
            }
            break;
        }
        case 4: {
            void* cam = fn_80107E74(g_IfAdvMngr);
            if (self->m_50 != 0) {
                if (isAlive__10adAutoSaveFv(cam) == 0) {
                    self->m_c1 = 5;
                    self->m_50 = 0;
                    return;
                }
            } else {
                self->m_c1 = 5;
                return;
            }
            break;
        }
        case 5:
            fn_80158BE0();
            fn_80159420();
            self->m_c1 = 6;
            return;
        case 6:
            fn_80158BE0();
            if (fn_8015A33C() != 0) {
                fn_80158BE0();
                fn_8015A358();
                self->m_c1 = 0;
                fn_80107E74(g_IfAdvMngr);
            }
            break;
        }
    }
}
