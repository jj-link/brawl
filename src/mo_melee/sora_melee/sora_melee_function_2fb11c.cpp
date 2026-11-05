#include <mt/mt_vector.h>
#pragma force_active on
class soNullable {
public:
 virtual void isNull();
 virtual void slot1();
 virtual void slot2();
 virtual void slot3();
 virtual int slot4(int);
 virtual void slot5(int,int);
 virtual void slot6();
 virtual void slot7();
 virtual void slot8();
 virtual void slot9();
 virtual void slot10();
 virtual int slot11(int,int,const Vec3f&,const Vec3f&,float,int,int,int,int);
 virtual void slot12();
 virtual void slot13();
 virtual void slot14();
 virtual void slot15();
 virtual void slot16();
 virtual void slot17();
 virtual void slot18();
 virtual void slot19();
 virtual void slot20();
 virtual void slot21();
 virtual void slot22(int,int,int);
};
struct gfTask_base { char pad[0x3c]; };
class gfTask : public gfTask_base {
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
 virtual void slot32();
 virtual void slot33();
 virtual void slot34();
 virtual void slot35();
 virtual void slot36();
 virtual void slot37();
 virtual void slot38();
 virtual void fn_27_248088();
 virtual int slot40();
};

extern "C" {
int* fn_27_1492A4(void*, int);
extern char g_ftCommonDataAccesser[];
extern const float lbl_27_rodata_6508[4];
}
extern "C" void fn_27_2FB11C(void* unused, char* p) {
    gfTask* a = *(gfTask**)(p + 0x8);
    const float* k = lbl_27_rodata_6508;
    char* b = *(char**)(p + 0xD8);
    soNullable* o28 = *(soNullable**)(b + 0x64);
    soNullable* o27 = *(soNullable**)(b + 0x88);
    int kind = a->slot40();
    int* data = fn_27_1492A4(&g_ftCommonDataAccesser, kind);

    if (o28->slot4(0x10000041) >= *data) {
        if (o28->slot4(0x10000040) == 0) {
            int res;
            if (kind == 3) {
                res = o27->slot11(0x40006, 0x2B,
                    Vec3f(k[1], k[0], k[0]), Vec3f(k[0], k[0], k[0]),
                    k[2], 1, 0, 0, -1);
            } else {
                res = o27->slot11(0x01080004, 0x1B8,
                    Vec3f(k[0], k[0], k[0]), Vec3f(k[0], k[0], k[0]),
                    k[2], 1, 0, 0, -1);
            }
            o28->slot5(res, 0x10000040);
        }
    } else if (o28->slot4(0x10000040) != 0) {
        int r = o28->slot4(0x10000040);
        o27->slot22(r, 1, 1);
        o28->slot5(0, 0x10000040);
    }
}
