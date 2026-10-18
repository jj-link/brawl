#pragma force_active on
typedef unsigned int u32;

struct Entry {
    char pad[0x30];
    u32 value;
    unsigned char pad34[2];
    unsigned char kind;
};

struct Count {
    u32 pad;
    u32 count;
};

struct Container {
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual Entry* get(u32);

    u32 pad;
    Count* data;
};

struct GroundBase {
    char pad[0x3c];
};

#define V(n) virtual void v##n();

struct Ground : GroundBase {
    V(2) V(3) V(4) V(5) V(6) V(7) V(8) V(9)
    V(10) V(11) V(12) V(13) V(14) V(15) V(16) V(17) V(18) V(19)
    V(20) V(21) V(22) V(23) V(24) V(25) V(26) V(27) V(28) V(29)
    V(30) V(31) V(32) V(33) V(34) V(35) V(36) V(37) V(38)
    virtual void init(void*, int, int);
    V(40) V(41) V(42) V(43) V(44) V(45) V(46) V(47) V(48) V(49)
    V(50) V(51) V(52) V(53) V(54) V(55) V(56) V(57) V(58) V(59)
    V(60) V(61) V(62) V(63) V(64) V(65) V(66) V(67) V(68) V(69)
    V(70) V(71) V(72) V(73) V(74) V(75) V(76) V(77) V(78) V(79)
    V(80) V(81)
    virtual void set(Entry*);
};

#undef V

struct Stage {
    char pad[0x1a0];
    void* data;
};

extern "C" {
extern char lbl_40_data_C0[];

Ground* fn_40_24C94(short, u32, const char*);
void addGround__5StageFP6Ground(Stage*, Ground*);
Container* searchContainer__20stDataMultiContainerFUlUl(
    void*, unsigned long, unsigned long);

void fn_40_D074(Stage* stage, unsigned long type, void* multi) {
    Ground* ground;
    Container* container;
    u32 index = 0;
    u32 i;
    Entry* entry;

    while ((container = searchContainer__20stDataMultiContainerFUlUl(
                multi, type, index++)) != 0) {
        for (i = 0; i < container->data->count; ++i) {
            entry = container->get(i);
            ground = fn_40_24C94(entry->kind, entry->value, lbl_40_data_C0);
            if (ground) {
                addGround__5StageFP6Ground(stage, ground);
                ground->set(entry);
                ground->init(stage->data, 0, 0);
            }
        }
    }
}
}
