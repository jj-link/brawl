#pragma force_active on

struct Vec3f {
    float x, y, z;
};

struct Item {
    char pad[0x3c];

#define V1(n) virtual void unused##n();
#define V2(n) V1(n##a) V1(n##b)
#define V4(n) V2(n##a) V2(n##b)
#define V8(n) V4(n##a) V4(n##b)
#define V16(n) V8(n##a) V8(n##b)
#define V32(n) V16(n##a) V16(n##b)
#define V64(n) V32(n##a) V32(n##b)
#define V128(n) V64(n##a) V64(n##b)
    V128(a)
    V16(b)
    V4(c)
    V1(d)
#undef V1
#undef V2
#undef V4
#undef V8
#undef V16
#undef V32
#undef V64
#undef V128

    virtual void call(int, int, int);
    char pad40[0x87c];
    int id;
};

struct Node {
    char pad[8];
    Vec3f pos;
};

struct Handle {
    void* unused;
    Node* node;
};

extern "C" {
extern void* g_GameGlobal;
unsigned int fn_8004E96C(void*);
void* getInstance__9itManagerFv();
Item* createItem__9itManagerF6itKindUliP16soResourceModuleUciii(
    void*, int, unsigned long, int, void*, unsigned char, int, int, int);
void warp__8BaseItemFP5Vec3f(Item*, Vec3f*);
extern float lbl_56_rodata_A0;
extern float lbl_56_rodata_A4;
}

extern "C" void fn_56_3734(char* self) {
    if (*(unsigned char*)(self + 0x1b1) == 1) {
        if (fn_8004E96C(g_GameGlobal)) {
            *(unsigned char*)(self + 0x1b1) = 0;
            void* manager = getInstance__9itManagerFv();
            if (manager) {
                Item* item =
                    createItem__9itManagerF6itKindUliP16soResourceModuleUciii(
                        manager, 0x40, 5000, -1, 0, 0, 0xffff, 0, 0xffff);
                if (item) {
                    item->call(-1, 0, -1);
                    Handle* handle = (Handle*)(self + 0xd0);
                    if (handle) {
                        Node* node = handle->node;
                        Vec3f pos;
                        pos.x = node->pos.x;
                        pos.y = node->pos.y;
                        pos.z = node->pos.z;
                        pos.y -= lbl_56_rodata_A0;
                        pos.z += lbl_56_rodata_A4;
                        warp__8BaseItemFP5Vec3f(item, &pos);
                    }
                    *(int*)(self + 0x1ac) = item->id;
                }
            }
        }
    }
}
