#include <it/it_manager.h>
#include <it/item.h>
#include <mt/mt_vector.h>
#pragma force_active on

class Class_1250 {
public:
    virtual void fn_27_13C90();
    virtual void fn_27_14068();
    virtual void fn_27_140C0();
    virtual void fn_27_1412C();
    virtual void fn_27_14134();
    virtual void fn_27_14370();
    virtual void fn_27_14A28();
    virtual void fn_27_14A30();
    virtual void fn_27_14A38();
    virtual float fn_27_14A48();
};

struct PostureBase {
    char pad[8];
};

class PostureModule : public PostureBase {
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
    virtual Vec3f fn_27_14Axx(int, int);
};

class Class_1F90 {
public:
    virtual void fn_27_1EFD0();
    virtual void fn_27_E240();
    virtual void fn_27_E190();
    virtual void fn_27_E1A0();
    virtual void fn_27_1D2D0();
    virtual void fn_27_1D200();
    virtual void fn_27_1D240();
    virtual void fn_27_1EF00();
    virtual int fn_27_1EF7C();
    virtual void fn_27_E200();
};

extern "C" {
extern const float lbl_27_rodata_E60;
extern const float lbl_27_rodata_E64;
void fn_8003DC64(Vec2f*, float, Vec2f*);
void fn_27_28F06C(BaseItem*, int);
void fn_27_28E108(BaseItem*, float, Vec3f*, float);
}

extern "C" int fn_27_B88AC(void* object, int kind, unsigned int variation,
                           int positionParam, float angle, float y, float speed) {
    float facing =
        ((Class_1250*)*(void**)((char*)*(void**)((char*)*(void**)((char*)object + 0x68) + 0xD8) + 0x0C))
            ->fn_27_14A48();

    void* posture =
        *(void**)((char*)*(void**)((char*)*(void**)((char*)object + 0x68) + 0xD8) + 0x04);
    Vec3f position = ((PostureModule*)posture)->fn_27_14Axx(positionParam, 0);

    itManager* manager = itManager::getInstance();
    BaseItem* item = manager->createItem(
        &position, facing, (itKind)kind, variation,
        *(int*)((char*)*(void**)((char*)*(void**)((char*)object + 0x68) + 0x08) + 0x28),
        0, 0, 0xFFFF, 0, 0xFFFF);

    if (item != 0) {
        void* ownerModule =
            *(void**)((char*)*(void**)((char*)*(void**)((char*)object + 0x68) + 0xD8) + 0x18);
        unsigned int resource = ((Class_1F90*)ownerModule)->fn_27_1EF7C();
        if (resource + 0x10000 == 0xFFFF)
            resource = *(int*)((char*)*(void**)((char*)*(void**)((char*)object + 0x68) + 0x08) + 0x28);

        fn_27_28F06C(item, resource);

        Vec2f offset;
        offset.m_x = y;
        offset.m_y = lbl_27_rodata_E60;
        fn_8003DC64(&offset, lbl_27_rodata_E64 * angle, &offset);

        facing =
            ((Class_1250*)*(void**)((char*)*(void**)((char*)*(void**)((char*)object + 0x68) + 0xD8) + 0x0C))
                ->fn_27_14A48();
        Vec3f velocity;
        float horizontal = offset.m_x * facing;
        offset.m_x = horizontal;
        velocity.m_x = horizontal;
        velocity.m_y = offset.m_y;
        velocity.m_z = lbl_27_rodata_E60;
        fn_27_28E108(item, facing, &velocity, speed);
        return 1;
    }

    return 0;
}
