#pragma force_active on
#include <string.h>
extern "C" {
void fn_800C2BB4(void*, int);
extern char lbl_6_data_0[];
extern char lbl_6_data_658[];
}
struct ViewerBase { char pad[0x3C]; };
struct Viewer : ViewerBase {
#define SLOT(n) virtual void unused##n();
    SLOT(1);
    SLOT(2);
    SLOT(3);
    SLOT(4);
    SLOT(5);
    SLOT(6);
    SLOT(7);
    SLOT(8);
    SLOT(9);
    SLOT(10);
    SLOT(11);
    SLOT(12);
    SLOT(13);
    SLOT(14);
    SLOT(15);
    SLOT(16);
    SLOT(17);
    SLOT(18);
    SLOT(19);
    SLOT(20);
    SLOT(21);
    SLOT(22);
    SLOT(23);
    SLOT(24);
    SLOT(25);
    SLOT(26);
    SLOT(27);
    SLOT(28);
    SLOT(29);
    SLOT(30);
    SLOT(31);
    SLOT(32);
    SLOT(33);
    SLOT(34);
    SLOT(35);
    SLOT(36);
    SLOT(37);
    SLOT(38);
    SLOT(39);
    SLOT(40);
    SLOT(41);
    SLOT(42);
    virtual void fB0(void*);
    SLOT(44); SLOT(45);
    virtual int fBC(int);
    virtual void fC0(int, int);
    SLOT(48);
    SLOT(49);
    SLOT(50);
    SLOT(51);
    SLOT(52);
    SLOT(53);
    SLOT(54);
    SLOT(55);
    SLOT(56);
    SLOT(57);
    SLOT(58);
    SLOT(59);
    SLOT(60);
    SLOT(61);
    SLOT(62);
    SLOT(63);
    SLOT(64);
    SLOT(65);
    SLOT(66);
    SLOT(67);
    SLOT(68);
    SLOT(69);
    SLOT(70);
    SLOT(71);
    SLOT(72);
    SLOT(73);
    SLOT(74);
    SLOT(75);
    SLOT(76);
    SLOT(77);
    SLOT(78);
    SLOT(79);
    SLOT(80);
    SLOT(81);
    SLOT(82);
    SLOT(83);
    SLOT(84);
    SLOT(85);
    SLOT(86);
    SLOT(87);
    SLOT(88);
    SLOT(89);
    SLOT(90);
    SLOT(91);
    virtual void f174(int, int);
#undef SLOT
};
struct ResourceBase { char pad[0x50]; };
struct Resource : ResourceBase { virtual void f0(int); };
extern "C" void fn_6_7564(char* self) {
    int var_r27;
    char* sub;
    char* temp_r26;
    char* name;
    char* fmt;
    unsigned int var_r24;
    Resource* q;
    var_r27 = 0;
    unsigned int idx = (*(unsigned int*)(*(char**)(self + 0x1ac) + 0x1a0) == 0);
    sub = *(char**)(*(char**)(self + 0x1ac) + 0x1ce4) + idx * 0x14;
    if (((Viewer*)self)->fBC(idx) != 0) {
        if (((unsigned char*)sub)[0x358] != 0) var_r27 = 1;
    }
    if (var_r27 != 0) {
        if (*(int*)(*(char**)(*(char**)(self + 0x1ac) + 0x1ce4) + 0x350) == 0) {
            char* temp_r23;
            char* var_r22;
            temp_r26 = *(char**)(self + 0x1ac) + 0x1c8;
            name = lbl_6_data_0;
            var_r22 = temp_r26;
            var_r24 = 0;
            do {
                bool ne = strcmp(var_r22, name) != 0;
                if (ne) {
                    var_r22[0] = 0;
                    strcat(var_r22, lbl_6_data_658);
                    temp_r23 = (char*)(((unsigned long)(var_r22 + 0x4f)) & ~7UL);
                    if (temp_r23 != 0 && temp_r23 != 0) {
                        if (temp_r23 + 0xc != 0) {
                            q = *(Resource**)(temp_r23 + 0xc);
                            if (q != 0) q->f0(1);
                        }
                        if (temp_r23 != 0) {
                            if (temp_r23 != 0) fn_800C2BB4(temp_r23, 0);
                        }
                    }
                    *(int*)(var_r22 + 0x44) = 0x3d;
                }
                ++var_r24;
                var_r22 += 0x68;
            } while (var_r24 < 0x3e);
            *(int*)(temp_r26 + 0x1930) = 0;
            ((Viewer*)self)->fC0(idx, 1);
            ((Viewer*)self)->f174(0, *(int*)(*(char**)(self + 0x1ac) + 0x1a0));
            *(int*)(*(char**)(self + 0x1ac) + 0x1a0) = idx;
            *(int*)(*(char**)(self + 0x1ac) + 0x1bfc) = 0;
            ((Viewer*)self)->fB0(*(void**)(*(char**)(*(char**)(self + 0x1ac) + 0x160) + 0x10));
        }
    } else {
        *(int*)(*(char**)(self + 0x1ac) + 0x1bfc) = 10;
    }
}