#pragma force_active on

class stFamicom {
public:
    char pad[0x3c];
    virtual void processDefault();
    virtual void processBegin();
    virtual void processAnim();
    virtual void processUpdate();
    virtual void processPreMapCorrection();
    virtual void processMapCorrection();
    virtual void processFixPosition();
    virtual void processPreCollision();
    virtual void processCollision();
    virtual void processCatch();
    virtual void processHit();
    virtual void processCamera();
    virtual void processFixCamera();
    virtual void processEffect();
    virtual void processGameProc();
    virtual void processEnd();
    virtual void renderPre();
    virtual void renderOpa();
    virtual void renderXlu();
    virtual void processDebug();
    virtual void renderDebug();
    virtual void init();
    virtual void fn_68_350();
    virtual void fn_68_4C4();
    virtual void createObjPokeTrainer();
    virtual void fn_68_2254();
    virtual void fn_68_2250();
    virtual void fn_68_2244(int);

    char data[0x124];
    float f164;
    float f168;
    float f16C;
    float f170;
    unsigned char u174;
    unsigned char u175;
    char pad176[2];
    void* p178;
    char pad17C[0x2C];
    int i1a8;
};

struct Vec3 {
    float x;
    float y;
    float z;
};

extern "C" {
extern const float lbl_68_rodata_148[];
void* getInstance__9itManagerFv();
void* createItem__9itManagerF6itKindUliP16soResourceModuleUciii(void*, int, unsigned long, int, void*, int, int, int, int);
void warp__8BaseItemFP5Vec3f(void*, void*);
void fn_27_28E48C(void*, void*, float);
}

extern "C" void fn_68_EB58(stFamicom* self) {
    const float* c = lbl_68_rodata_148;
    if (self->i1a8 == 0) {
        void* mgr = getInstance__9itManagerFv();
        if (mgr != 0) {
            void* item = createItem__9itManagerF6itKindUliP16soResourceModuleUciii(
                mgr, 0x4c, self->u174 - 1u, -1, 0, 0, 0xFFFF, 0, 0xFFFF);
            if (item != 0) {
                float* p = (float*)((char*)self->p178 + (int)self->u175 * 0x28);
                Vec3 vec;
                vec.x = p[0];
                vec.y = p[1];
                vec.z = p[2];
                vec.y += c[5];
                warp__8BaseItemFP5Vec3f(item, &vec);
                Vec3 vec2;
                vec2.x = c[0];
                vec2.y = c[6];
                vec2.z = c[0];
                float lr;
                if (c[7] == self->f170) {
                    vec2.x = self->f164;
                    lr = c[3];
                } else if (c[3] == self->f170) {
                    vec2.x = -self->f164;
                    lr = c[7];
                } else {
                    float* p2 = (float*)((char*)self->p178 + (int)self->u175 * 0x28);
                    if (c[1] == p2[4]) {
                        lr = c[7];
                    } else {
                        lr = c[3];
                    }
                }
                fn_27_28E48C(item, &vec2, lr);
                self->i1a8 = *(int*)((char*)item + 0x8bc);
                self->fn_68_2244(0);
            }
        }
    }
}
