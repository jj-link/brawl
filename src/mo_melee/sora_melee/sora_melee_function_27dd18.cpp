#include <ft/ft_manager.h>
#include <if/if_mngr.h>
#pragma force_active on

struct Vec3 {
    float x, y, z;
};

class SelfBase {
public:
    virtual void s00();
    virtual void s01();
    virtual void s02();
    virtual void s03();
    virtual void s04();
    virtual void s05();
    virtual void s06();
    virtual void s07();
    virtual void s08();
    virtual void s09();
    virtual void s10();
    virtual void s11();
    virtual void s12();
    virtual void s13();
    virtual void s14();
    virtual void s15();
    virtual void s16();
    virtual void s17();
    virtual void s18();
    virtual void s19();
    virtual void s20();
    virtual void s21();
    virtual void s22();
    virtual void s23();
    virtual void s24();
    virtual void s25();
    virtual void s26();
    virtual void s27();
    virtual void s28();
    virtual void s29();
    virtual void s30();
    virtual void s31();
    virtual void s32();
    virtual void s33();
    virtual void s34();
    virtual void s35();
    virtual void s36();
    virtual void s37();
    virtual void s38();
    virtual void s39();
    virtual void s40();
    virtual void s41();
    virtual void s42();
    virtual int s43();
};

class Self : public SelfBase {
public:
    char pad04[8];
    void* data; // 0xc
    char pad10[0x24];
    union {
        unsigned char flags;
        struct { unsigned char a : 3; unsigned char bit : 1; unsigned char b : 4; } bits;
    };
    char pad35[3];
    int unk38; // 0x38
};

struct GmkBase {
    char pad[0x3c];
};

class Gmk : public GmkBase {
public:
    virtual void n00();
    virtual void n01();
    virtual void n02();
    virtual void n03();
    virtual void n04();
    virtual void n05();
    virtual void n06();
    virtual void n07();
    virtual void n08();
    virtual void n09();
    virtual void n10();
    virtual void n11();
    virtual void n12();
    virtual void n13();
    virtual void n14();
    virtual void n15();
    virtual void n16();
    virtual void n17();
    virtual void n18();
    virtual void n19();
    virtual void n20();
    virtual void n21();
    virtual void n22();
    virtual void n23();
    virtual void n24();
    virtual void n25();
    virtual void n26();
    virtual void n27();
    virtual void n28();
    virtual void n29();
    virtual void n30();
    virtual void n31();
    virtual void n32();
    virtual void n33();
    virtual void n34();
    virtual void n35();
    virtual void n36();
    virtual void n37();
    virtual void n38();
    virtual void n39();
    virtual void n40();
    virtual void n41();
    virtual void n42();
    virtual void n43();
    virtual void n44();
    virtual void n45();
    virtual void n46();
    virtual void n47();
    virtual void n48();
    virtual void n49();
    virtual void n50();
    virtual void n51();
    virtual void n52();
    virtual void n53();
    virtual void n54();
    virtual void n55();
    virtual void n56();
    virtual void n57();
    virtual void n58();
    virtual void n59();
    virtual void n60();
    virtual void n61();
    virtual void n62();
    virtual void n63();
    virtual void n64();
    virtual void n65();
    virtual void n66();
    virtual void n67();
    virtual void n68();
    virtual void n69();
    virtual void n70();
    virtual void n71();
    virtual void n72();
    virtual void n73();
    virtual void n74();
    virtual void n75();
    virtual void n76();
    virtual void n77();
    virtual void n78();
    virtual void n79();
    virtual void n80();
    virtual void n81();
    virtual void n82();
    virtual void n83();
    virtual void n84();
    virtual void n85();
    virtual void n86();
    virtual void n87();
    virtual void n88();
    virtual int n89();   // 0x16c
    virtual int n90(int); // 0x170
};

extern "C" {
void fn_800E5644(void*, int, void*);
void fn_800E57FC(void*, Vec3*);
void fn_27_10AD38(Vec3*, ftManager*, int, int);
int fn_27_10AAC4(ftManager*, int);
}

extern void* lbl_27_bss_5668;

extern "C" void fn_27_27DD18(Self* self, int entry, int kind) {
    if (self->s43() == 0) {
        return;
    }
    if (((self->flags >> 6) & 1) && kind < 4 && g_IfMngr != 0) {
        int playerNo = g_ftManager->getPlayerNo(entry);
        unsigned char idx = *(unsigned char*)((char*)self->data + playerNo * 0x5c + 0x9a);
        fn_800E5644(*(void**)((char*)g_IfMngr + ((unsigned char*)g_IfMngr + idx)[0x68] * 4 + 0x4c),
                    kind, g_IfMngr);
        Vec3 pos;
        fn_27_10AD38(&pos, g_ftManager, entry, -1);
        fn_800E57FC(*(void**)((char*)g_IfMngr + ((unsigned char*)g_IfMngr + idx)[0x68] * 4 + 0x4c),
                    &pos);
    }
    if (kind == 4) {
        switch (fn_27_10AAC4(g_ftManager, entry)) {
        case 7:
            if (*(unsigned short*)((char*)self->data + 0x1a) == 0x13 && lbl_27_bss_5668 != 0) {
                ((Gmk*)lbl_27_bss_5668)->n90(0);
                self->bits.bit = ((Gmk*)lbl_27_bss_5668)->n89();
                self->unk38 = entry;
                self->flags |= 0x10;
            }
            if (*(unsigned short*)((char*)self->data + 0x1a) == 0x30 && lbl_27_bss_5668 != 0) {
                ((Gmk*)lbl_27_bss_5668)->n90(0);
                self->bits.bit = ((Gmk*)lbl_27_bss_5668)->n89();
                self->unk38 = entry;
            }
            break;
        case 0x15:
            if (*(unsigned short*)((char*)self->data + 0x1a) == 0x13 && lbl_27_bss_5668 != 0) {
                ((Gmk*)lbl_27_bss_5668)->n90(1);
                self->bits.bit = ((Gmk*)lbl_27_bss_5668)->n89();
                self->unk38 = entry;
            }
            if (*(unsigned short*)((char*)self->data + 0x1a) == 0x30 && lbl_27_bss_5668 != 0) {
                ((Gmk*)lbl_27_bss_5668)->n90(1);
                self->bits.bit = ((Gmk*)lbl_27_bss_5668)->n89();
                self->unk38 = entry;
            }
            break;
        case 0x29:
            if (*(unsigned short*)((char*)self->data + 0x1a) == 0x13 && lbl_27_bss_5668 != 0) {
                ((Gmk*)lbl_27_bss_5668)->n90(2);
                self->bits.bit = ((Gmk*)lbl_27_bss_5668)->n89();
                self->unk38 = entry;
            }
            break;
        case 0x2a:
            if (*(unsigned short*)((char*)self->data + 0x1a) == 0x22 && lbl_27_bss_5668 != 0) {
                ((Gmk*)lbl_27_bss_5668)->n90(0);
                self->bits.bit = ((Gmk*)lbl_27_bss_5668)->n89();
                self->unk38 = entry;
            }
            break;
        }
    } else {
        if (*(unsigned short*)((char*)self->data + 0x1a) == 0x1c && lbl_27_bss_5668 != 0) {
            int player = g_ftManager->getPlayerNo(entry);
            *((unsigned char*)lbl_27_bss_5668 + (unsigned char)player + 0x9e3) = 1;
        }
    }
}
