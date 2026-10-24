#pragma force_active on

struct Vec3 {
    float x, y, z;

    Vec3() {}
    Vec3(const Vec3& v) {
        __memcpy(this, &v, sizeof(Vec3));
    }
    Vec3(float a, float b, float c) : x(a), y(b), z(c) {}

    Vec3& operator=(const Vec3& v) {
        x = v.x;
        y = v.y;
        z = v.z;
        return *this;
    }
};

struct PikminVector {
    float x, y, z;
};

class soPhotoController {
public:
    void setFreezeMode();
};

class Posture {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual Vec3 getPos();
    virtual void setPos(Vec3*);
};

struct Base {
    char pad[0x3c];
};

class Target : public Base {
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
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void change(Vec3*, int);
    int state;
};

extern "C" {
extern void* g_ftManager;
extern void* g_cmAIController;
extern float lbl_113_rodata_150;
extern float lbl_113_rodata_164;
extern Target* lbl_27_bss_5668;

void fn_27_1DA1F4(void*);
void fn_27_10D948(void*, int);
void fn_27_10D95C(void*);
unsigned int fn_27_8E8DC(float);
PikminVector* fn_113_A1D0(PikminVector*, float, float, float);
void fn_8009FCC8(void*, void*, float*);
}

inline Posture* posture(void* self) {
    return *(Posture**)(*(char**)(*(char**)((char*)self + 0x60) + 0xd8) + 0xc);
}

inline Vec3 getPosition(Posture* p) {
    return p->getPos();
}

inline void resetCamera() {
    void* controller = g_cmAIController;
    if (controller) {
        float buf[2];
        PikminVector vec;
        float f = lbl_113_rodata_150;
        buf[0] = f;
        buf[1] = f;
        PikminVector* r = fn_113_A1D0(&vec, f, f, f);
        fn_8009FCC8(controller, r, buf);
    }
}

extern "C" void fn_113_2988C(void* self, int a, int b) {
    fn_27_1DA1F4(self);

    switch (a) {
    case 2:
        fn_27_10D948(g_ftManager, 0);
        break;
    case 1:
        ((soPhotoController*)1)->setFreezeMode();
        break;
    }

    if (b == 2) {
        fn_27_10D95C(g_ftManager);
        Target* obj = lbl_27_bss_5668;
        if (obj) {
            Vec3 original = getPosition(posture(self));
            Vec3 pos = original;

            switch (*(int*)((char*)obj + 0x44)) {
            case 0x23:
            case 0x2a:
            case 0x33:
                if (fn_27_8E8DC(lbl_113_rodata_164) == 1U) {
                    obj->change(&pos, 3);
                } else {
                    obj->change(&pos, 4);
                }
                break;
            default:
                obj->change(&pos, 2);
                break;
            }

            original.x = pos.x;
            posture(self)->setPos(&original);
        }
    } else if (b == 1) {
        *(Vec3*)((char*)self + 0x241c) = getPosition(posture(self));
    } else if (b == 3) {
        resetCamera();
    }
}
