#pragma force_active on

struct Vec3f {
    float x, y, z;
};

#define V1(n) virtual void unused##n();
#define V2(n) V1(n##a) V1(n##b)
#define V4(n) V2(n##a) V2(n##b)
#define V8(n) V4(n##a) V4(n##b)
#define V16(n) V8(n##a) V8(n##b)
#define V32(n) V16(n##a) V16(n##b)
#define V64(n) V32(n##a) V32(n##b)

struct Obj {
    char pad[0x3C];
    V32(a) V16(b)
    virtual void call50(Vec3f*, int, int);
    V64(d) V32(e) V4(f)
    virtual void call151(int, int, int);
};

extern "C" {
extern void* g_GameGlobal;
extern float lbl_70_rodata_EC;
extern float lbl_70_rodata_F0;
int fn_8004E96C(void*);
void* getInstance__9itManagerFv();
void* createItem__9itManagerF6itKindUliP16soResourceModuleUciii(void*, int, unsigned long, int, void*, unsigned char, int, int, int);
void setVanishMode__8BaseItemFb(void*, bool);
void warp__8BaseItemFP5Vec3f(void*, Vec3f*);
}

extern "C" void fn_70_6FE8(Obj* self) {
    Vec3f pos;
    if (*(unsigned char*)((char*)self + 0x1E8) == 1) {
        if (fn_8004E96C(g_GameGlobal)) {
            *(unsigned char*)((char*)self + 0x1E8) = 0;
            void* manager = getInstance__9itManagerFv();
            if (manager) {
                self->call50(&pos, 0, *(int*)((char*)self + 0x1E4));
                pos.y = pos.y - lbl_70_rodata_EC;
                pos.z = pos.z + lbl_70_rodata_F0;
                Obj* item = (Obj*)createItem__9itManagerF6itKindUliP16soResourceModuleUciii(manager, 0x40, 0x1388, -1, 0, 0, 0xFFFF, 0, 0xFFFF);
                if (item) {
                    item->call151(-1, 0, -1);
                    setVanishMode__8BaseItemFb(item, false);
                    warp__8BaseItemFP5Vec3f(item, &pos);
                    *(int*)((char*)self + 0x1E0) = *(int*)((char*)item + 0x8BC);
                }
            }
        }
    }
}
