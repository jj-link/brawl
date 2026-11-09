#pragma force_active on

typedef unsigned int u32;

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
    virtual void processCamera();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void renderOpa();
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual void init();
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
    virtual int slot32(int* out);
};

extern "C" {
void* getInstance__9itManagerFv();
void* getManager__11soArchiveDbFUl(u32);
void* fn_800455E0(void*, int);
u32 fn_800453AC(void*, int, int, int, int, int, int, void*, int);
extern char lbl_27_data_7AC70[];
extern void* lbl_27_bss_5668;
extern char g_HeapInfos[];
extern int lbl_805A00C0;
}

extern "C" void* fn_27_2C2A00(void* self, int kind, int variation) {
    *(int*)self = kind;
    *(char**)((char*)self + 0x10) = lbl_27_data_7AC70;
    *(u32*)((char*)self + 4) = 0xFFFF;
    *((char*)self + 8) = 0;
    *(int*)((char*)self + 0xC) = 0;

    int heap = 0x24;
    void* mgr = getInstance__9itManagerFv();
    if (*(int*)((char*)mgr + 0x50) == 3 || (u32)kind + 0x10000 == 0xFFF0) {
        if (*(int*)(g_HeapInfos + 0x260) != 0)
            heap = 0x26;
    } else if ((u32)kind + 0x10000 == 0xFFF1) {
        if (lbl_27_bss_5668 != 0) {
            int id = 0;
            ((Object_vptr_3c*)lbl_27_bss_5668)->slot32(&id);
            int found = id;
            if (found != 0) {
                void* archive = getManager__11soArchiveDbFUl(2);
                *(u32*)((char*)self + 4) = (u32)fn_800455E0(archive, found);
            }
        }
    } else if (*(int*)(g_HeapInfos + 0x240) != 0) {
        heap = 0x24;
    } else if (*(int*)(g_HeapInfos + 0x80) != 0) {
        heap = 8;
    }

    if (*(u32*)((char*)self + 4) == 0xFFFF) {
        void* archive = getManager__11soArchiveDbFUl(2);
        *(u32*)((char*)self + 4) = fn_800453AC(archive, variation, heap, 0, 0, 0, 0xFF, &lbl_805A00C0, 1);
    }
    return self;
}
