#pragma force_active on
struct Vec { float x, y, z; };
struct Pair { unsigned int x, y; Pair(unsigned int a, unsigned int b) : x(a), y(b) {} };
struct Mode { char pad[0x16]; signed char enabled; };
struct Global { char pad[8]; Mode* mode; };
struct Base {
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
 virtual void getPos(Vec*, int, unsigned int);
};
struct Obj : Base { char pad1[0x230]; unsigned int id; };
extern "C" {
extern Global* g_GameGlobal;
extern const float lbl_66_rodata_D8;
extern char* lbl_27_bss_5668;
void* getInstance__9itManagerFv();
void fn_27_2AA7AC(void*, Pair, int, Vec*, int, int, int, unsigned int);
void fn_66_57B4(Obj* self) {
    Mode* mode = g_GameGlobal->mode;
    if (mode && mode->enabled) {
        Vec pos;
        self->getPos(&pos, 0, self->id);
        pos.x -= lbl_66_rodata_D8;
        pos.y += lbl_66_rodata_D8;
        void* mgr = getInstance__9itManagerFv();
        if (mgr) {
            unsigned int id = *(unsigned int*)(lbl_27_bss_5668 + 0x44);
            fn_27_2AA7AC(mgr, Pair(id, 0), 2, &pos, -1, -1, -1, id);
        }
    }
}
}