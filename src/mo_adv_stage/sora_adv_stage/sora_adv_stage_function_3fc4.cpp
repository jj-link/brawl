#include <types.h>
#include <mt/mt_vector.h>
#include <st/st_utility.h>
#pragma force_active on

struct Point2 {
    float x;
    float y;
};

struct PointList {
    void* data;
    u32 count;
    u32 capacity;
};

struct Object_vptr_0_Data {
    char pad[4];
    u8 kind;
};

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual Object_vptr_0_Data* slot3(u32);
};

struct Object_vptr_3c_base {
    char pad[0x3c];
};

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
    virtual void slot11();
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
    virtual void slot39();
    virtual void slot40();
    virtual void slot41();
    virtual void slot42();
    virtual void slot43();
    virtual void slot44();
    virtual void slot45();
    virtual void slot46();
    virtual void slot47();
    virtual void slot48();
    virtual void slot49();
    virtual void slot50();
    virtual void slot51();
    virtual void slot52();
    virtual void slot53(Vec3f*, int);

    char pad40[0x524 - 0x40];
    void* data524;
    char pad528[0x578 - 0x528];
    void* data578;
    u32 pad57c;
    u32 count580;
    Point2* points584;
};

struct Constants {
    char pad[0x2c];
    float zero;
    char pad30[0x40];
    float rayLength;
    float height;
};

struct BssData {
    char pad[0xdc];
    u32 containerKind;
};

extern Constants lbl_40_rodata_0;
extern BssData lbl_40_bss_8;

extern "C" {
void fn_40_4414(PointList*);
void fn_40_44C(Vec3f*);
void fn_40_CF8(Vec3f*, float, float, float);
grCollision* fn_27_222878(void*, u32);
u32 fn_27_2228F8(void*);
Point2* fn_40_3FB8(Point2*, float, float);
void fn_40_44A0(PointList*, const Point2*);
void fn_40_450();
void* fn_40_38B8();
u32 fn_40_3D3C(Object_vptr_0*);
void fn_40_47B0(void*, Vec3f*, u8);
Object_vptr_0* searchContainer__20stDataMultiContainerFUlUl(void*, u32, u32);
float* fn_40_2E3CC(void*, u32);
Vec3f* fn_40_43F0(Vec3f*, const float*, float);
void fn_40_D08(Vec3f*, const Vec3f*);
u32 fn_40_4408(void*);
u32 fn_40_4798(PointList*);
Point2* fn_40_47A0(PointList*, u8);
void fn_40_2010(Point2*, const Point2*);
void fn_40_4428(PointList*, int);
void fn_40_4410();
void* __nwa__FUlQ25Heaps8HeapType(u32, int);
void* __construct_new_array(void*, void (*)(), void*, u32, u32);
}

extern "C" void fn_40_3FC4(Object_vptr_3c* self, void* multi)
{
    Constants* constants = &lbl_40_rodata_0;
    u32 count;
    PointList points;
    Vec3f start;
    Vec3f direction;
    Vec3f hit;
    Vec3f normal;

    fn_40_4414(&points);
    fn_40_44C(&start);
    fn_40_44C(&direction);
    fn_40_44C(&hit);
    fn_40_44C(&normal);
    fn_40_CF8(&direction, constants->zero,
              constants->rayLength, constants->zero);

    Object_vptr_0* container;
    u32 containerIndex = 0;
    self->slot53(&start, 0);
    for (u32 i = 0; i < fn_27_2228F8(self); i++) {
        if (stRayCheck(&start, &direction, &hit, &normal, false,
                       fn_27_222878(self, i), false, 4) == 1) {
            Point2 point;
            fn_40_44A0(&points, fn_40_3FB8(&point, hit.m_x, hit.m_y));
            break;
        }
    }

    if (((u8*)self->data524)[0x604] == 3) {
        fn_40_450();
        u8 kind = ((u8*)fn_40_38B8())[0x150];
        if (kind >= 0x1d && kind <= 0x22) {
            self->slot53(&start, 2);
            for (u32 i = 0; i < fn_27_2228F8(self); i++) {
                if (stRayCheck(&start, &direction, &hit, &normal, false,
                               fn_27_222878(self, i), false, 4) == 1) {
                    Point2 point;
                    fn_40_44A0(&points, fn_40_3FB8(&point, hit.m_x, hit.m_y));
                    break;
                }
            }
        }
    }

    if (multi) {
        while ((container = searchContainer__20stDataMultiContainerFUlUl(
                    multi, lbl_40_bss_8.containerKind, containerIndex++)) != 0) {
            for (u32 i = 0; i < fn_40_3D3C(container); i++) {
                fn_40_47B0(self, &start, container->slot3(i)->kind);
                for (u32 j = 0; j < fn_27_2228F8(self); j++) {
                    if (stRayCheck(&start, &direction, &hit, &normal, false,
                                   fn_27_222878(self, j), false, 4) == 1) {
                        Point2 point;
                        fn_40_44A0(&points, fn_40_3FB8(&point, hit.m_x, hit.m_y));
                        break;
                    }
                }
            }
        }
    }

    if (self->data578) {
        for (u32 i = 0; i < fn_40_4408(self->data578); i++) {
            Vec3f position;
            fn_40_D08(&start, fn_40_43F0(&position,
                                        fn_40_2E3CC(self->data578, i),
                                        constants->zero));
            for (u32 j = 0; j < fn_27_2228F8(self); j++) {
                if (stRayCheck(&start, &direction, &hit, &normal, false,
                               fn_27_222878(self, j), false, 4) == 1) {
                    Point2 point;
                    fn_40_44A0(&points, fn_40_3FB8(&point, hit.m_x, hit.m_y));
                    break;
                }
            }
        }
    }

    count = self->count580 = fn_40_4798(&points);
    void* memory = __nwa__FUlQ25Heaps8HeapType(count * 8 + 0x10, 15);
    self->points584 = (Point2*)__construct_new_array(memory, fn_40_4410, 0, 8, count);

    float height = constants->height;
    for (u8 i = 0; i < self->count580; i++) {
        fn_40_47A0(&points, i)->y += height;
        fn_40_2010(&self->points584[i], fn_40_47A0(&points, i));
    }

    fn_40_4428(&points, -1);
}
