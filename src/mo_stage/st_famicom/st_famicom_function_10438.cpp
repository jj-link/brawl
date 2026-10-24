#pragma force_active on

class stFamicom {
public:
    char pad[0x3c];
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
    virtual void v27(int);

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
extern const float lbl_68_rodata_198[];
void* getInstance__9itManagerFv();
void* createItem__9itManagerF6itKindUliP16soResourceModuleUciii(void*, int, unsigned long, int, void*, int, int, int, int);
void warp__8BaseItemFP5Vec3f(void*, void*);
void fn_27_28E48C(void*, void*, float);
}

extern "C" void fn_68_10438(stFamicom* self) {
    const float* c = lbl_68_rodata_198;
    if (self->i1a8 == 0) {
        void* mgr = getInstance__9itManagerFv();
        if (mgr != 0) {
            void* item = createItem__9itManagerF6itKindUliP16soResourceModuleUciii(
                mgr, 0x4b, self->u174 - 1u, -1, 0, 0, 0xFFFF, 0, 0xFFFF);
            if (item != 0) {
                char* base = (char*)self->p178 + (int)self->u175 * 0x28;
                float* p = (float*)base;
                Vec3 vec;
                vec.x = p[0];
                vec.y = p[1];
                vec.z = p[2];
                vec.y += c[5];
                warp__8BaseItemFP5Vec3f(item, &vec);
                Vec3 vec2;
                vec2.x = c[1];
                vec2.y = c[6];
                vec2.z = c[1];
                float lr;
                if (c[7] == self->f170) {
                    vec2.x = self->f164;
                    lr = c[0];
                } else if (c[0] == self->f170) {
                    vec2.x = -self->f164;
                    lr = c[7];
                } else {
                    float* p2 = (float*)((char*)self->p178 + (int)self->u175 * 0x28);
                    if (c[2] == p2[4]) {
                        lr = c[7];
                    } else {
                        lr = c[0];
                    }
                }
                fn_27_28E48C(item, &vec2, lr);
                self->i1a8 = *(int*)((char*)item + 0x8bc);
                self->v27(0);
            }
        }
    }
}
