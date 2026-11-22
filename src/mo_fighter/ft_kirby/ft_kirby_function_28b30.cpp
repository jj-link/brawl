#include <mt/mt_vector.h>
#include <so/ground/so_ground_module_impl.h>
#pragma force_active on

struct KirbyObject {
    int value;
    unsigned char flag;
    unsigned char padding[3];
    float scalar;
    unsigned char padding2[4];
    unsigned char state;
};

class KirbyModule {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual int v4(unsigned int flag);
    virtual void v5();
    virtual void* v6(int a);
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual Vec2f v13(short* p);
    virtual int v14(int a, int b);
    virtual void v15();
    virtual void v16(int a, KirbyObject* obj, int b);
    virtual void v17(int a, int b, int c);
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
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual int v54();
};

struct KirbyAccesser {
    char pad0[0x10];
    soGroundModule* m3;
    char pad1[0x8];
    KirbyModule* m2;
    char pad2[0x34];
    KirbyModule* m6;
    char pad3[0xC];
    KirbyModule* m1;
    char pad4[0x14];
    KirbyModule* m4;
};

struct KirbyFighter {
    char pad[0xD8];
    KirbyAccesser* accesser;
};

extern "C" {
void* __dynamic_cast(void*, long, const void*, const void*, short);
float fn_96_28A30(Vec2f* v);
Vec2f fn_96_28E4C(const Vec2f* vector, float scale);
void fn_96_28E78(KirbyObject* object, int value);
extern const char lbl_96_data_CEF4[];
extern const char lbl_96_data_5E00[];
extern const float lbl_96_rodata_570;
extern const float lbl_96_rodata_57C;
}

typedef int (*IntCall3)(void*, int, int);
typedef Vec2f (*Vec2Call3)(void*, int, int);

static inline void** subVtable(void* object) {
    return *reinterpret_cast<void***>(reinterpret_cast<char*>(object) + 8);
}

static inline void reflectInner(Vec2f& speed, const Vec2f& normal, float dot) {
    speed = speed - fn_96_28E4C(&fn_96_28E4C(&normal, lbl_96_rodata_57C), dot);
}
static inline void reflect(Vec2f& speed, const Vec2f& normal, float dot) {
    reflectInner(speed, normal, dot);
}

extern "C" void fn_96_28B30(void* unused, KirbyFighter* ft) {
    int r29;
    int r30;
    short sp8;
    KirbyObject sp5C;
    Vec2f orig;
    Vec2f ret15;
    Vec2f ret59;

    if (ft->accesser->m1->v4(0x20000001) != 2) {
        r29 = ft->accesser->m1->v4(0x20000000);
        for (r30 = 0; r30 < ft->accesser->m2->v54(); r30++) {
            if (ft->accesser->m2->v14(r30, 0) != 0) {
                ft->accesser->m2->v17(r30, r29, 0);
            }
        }
    }
    if (ft->accesser->m3->isTouch(static_cast<grCollStatus::TouchMask>(0xF7), 0) != 0) {
        r29 = 1;
        sp8 = (short)r29;
        Vec2f::copy(orig, ft->accesser->m4->v13(&sp8));
        Vec2f::copy(ret15, orig);
        Vec2f::copy(ret59, ft->accesser->m3->getTouchNormal(static_cast<grCollStatus::TouchMask>(0xFF), 0));
        float magnitude = fn_96_28A30(&ret59);
        if (magnitude != lbl_96_rodata_570) {
            float f31 = ret59.m_x * ret15.m_x + ret59.m_y * ret15.m_y;
            reflect(ret15, ret59, f31);
            char* energy = static_cast<char*>(__dynamic_cast(ft->accesser->m4->v6(0), 0, lbl_96_data_CEF4, lbl_96_data_5E00, r29));
            *reinterpret_cast<Vec2f*>(energy + 8) = Vec2f(ret15.m_x, ret15.m_y);
            if (orig.m_x * ret15.m_x + orig.m_y * ret15.m_y < lbl_96_rodata_570) {
                fn_96_28E78(&sp5C, 0x1A);
                int sign = (ret59.m_x < lbl_96_rodata_570) ? -1 : 1;
                sp5C.scalar = (float)sign;
                ft->accesser->m6->v16(0, &sp5C, 0);
            }
        }
    }
}
