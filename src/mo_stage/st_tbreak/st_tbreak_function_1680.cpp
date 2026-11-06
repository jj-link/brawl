#include <it/it_manager.h>
#include <mt/mt_matrix.h>
#pragma force_active on

struct Object_vptr_3c_base { char pad[0x3c]; };
class Object_vptr_3c : public Object_vptr_3c_base {
public:
    virtual void processDefault();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void processPreMapCorrection();
    virtual void slot5();
    virtual void processFixPosition();
    virtual void processPreCollision();
    virtual void processCollision();
    virtual void processCatch();
    virtual void processHit();
    virtual void processCamera();
    virtual void slot12();
    virtual void processEffect();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void renderOpa();
    virtual void renderXlu();
    virtual void processDebug();
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
    virtual bool slot51(Matrix*, unsigned long, const char*);
};
struct Entry {
    const char* name;
    itKind kind;
    unsigned long variation;
};
extern Entry lbl_89_data_400[];
struct Self {
    char pad[0x230];
    Object_vptr_3c* ground;
};
extern "C" bool fn_89_1680(Self* self) {
    if (self->ground) {
        for (int i = 0; i < 16; ++i) {
            if (!itManager::getInstance()->isCompItemKindArchive(lbl_89_data_400[i].kind, lbl_89_data_400[i].variation, true))
                return false;
        }
        for (int i = 0; i < 16; ++i) {
            Matrix matrix(true);
            if (self->ground->slot51(&matrix, 0, lbl_89_data_400[i].name)) {
                BaseItem* item = itManager::getInstance()->createItem(lbl_89_data_400[i].kind, lbl_89_data_400[i].variation, -1, 0, 0, 0xffff, 0, 0xffff);
                if (item) {
                    Vec3f pos;
                    float z = matrix.m[2][3];
                    float y = matrix.m[1][3];
                    float x = matrix.m[0][3];
                    pos.m_y = y;
                    pos.m_x = x;
                    pos.m_z = z;
                    item->warp(&pos);
                    item->setVanishMode(false);
                }
            }
        }
    }
    return true;
}