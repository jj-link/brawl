#pragma force_active on
typedef unsigned char u8;

struct Owner;

struct Weapon {
    u8 pad[0x2208];
    Owner* owner;
    u8 pad220C[0xF];
    bool active;
};

struct Owner {
    u8 pad[0x18];
    bool active;
    u8 pad19[3];
    Weapon* weapon;
};

struct ManagerBase {
    u8 pad[0x24];
};

struct Manager : ManagerBase {
    virtual void dummy0();
    virtual void dummy1();
    virtual void dummy2();
    virtual Weapon* allocate(int);
    virtual void dummy4();
    virtual void init(Weapon*, int, int, int, int, int, float, int, float,
                      int, int, int, short);
};

extern "C" Manager* getInstance__15emWeaponManagerFv();

extern "C" void fn_41_2D2A0(
    Owner* self, int p1, float a, int p2, int p3, int p4,
    int p5, int p6, float b, int p7, int p8)
{
    if (self->weapon == 0) {
        Manager* manager = getInstance__15emWeaponManagerFv();
        Weapon* weapon = manager->allocate(1);
        if (weapon != 0) {
            manager = getInstance__15emWeaponManagerFv();
            manager->init(weapon, p4, p5, p6, 0, p1, a, p2, b,
                          p3, p7, p8, -1);
            weapon->owner = self;
            weapon->active = true;
            self->active = true;
            self->weapon = weapon;
        }
    }
}
