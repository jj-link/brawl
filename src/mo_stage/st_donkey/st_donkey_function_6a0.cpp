#pragma force_active on

extern "C" {
extern const char lbl_50_data_0[];
extern const float lbl_50_rodata_0;
}

#define SLOT(n) virtual void v##n();
struct Ground {
    char pad[0x3c];
    SLOT(0) SLOT(1) SLOT(2) SLOT(3) SLOT(4) SLOT(5)
    SLOT(6) SLOT(7) SLOT(8) SLOT(9) SLOT(10) SLOT(11)
    SLOT(12) SLOT(13) SLOT(14) SLOT(15) SLOT(16) SLOT(17)
    SLOT(18) SLOT(19) SLOT(20) SLOT(21) SLOT(22) SLOT(23)
    SLOT(24) SLOT(25) SLOT(26) SLOT(27) SLOT(28) SLOT(29)
    SLOT(30) SLOT(31) SLOT(32) SLOT(33) SLOT(34) SLOT(35)
    SLOT(36)
    virtual void v37(void*, int, int);
    SLOT(38)
    virtual void v39(int);
    SLOT(40) SLOT(41) SLOT(42) SLOT(43) SLOT(44) SLOT(45)
    SLOT(46) SLOT(47) SLOT(48) SLOT(49) SLOT(50) SLOT(51)
    SLOT(52) SLOT(53) SLOT(54) SLOT(55) SLOT(56) SLOT(57)
    SLOT(58) SLOT(59) SLOT(60) SLOT(61) SLOT(62) SLOT(63)
    SLOT(64) SLOT(65) SLOT(66) SLOT(67) SLOT(68) SLOT(69)
    SLOT(70) SLOT(71) SLOT(72) SLOT(73) SLOT(74) SLOT(75)
    SLOT(76) SLOT(77) SLOT(78) SLOT(79) SLOT(80) SLOT(81)
    SLOT(82) SLOT(83) SLOT(84) SLOT(85) SLOT(86) SLOT(87)
    SLOT(88) SLOT(89) SLOT(90) SLOT(91) SLOT(92) SLOT(93)
    SLOT(94) SLOT(95) SLOT(96) SLOT(97) SLOT(98) SLOT(99)
    SLOT(100) SLOT(101) SLOT(102) SLOT(103) SLOT(104) SLOT(105)
    SLOT(106) SLOT(107) SLOT(108) SLOT(109) SLOT(110) SLOT(111)
    SLOT(112) SLOT(113)
    virtual void v114(void*);
    virtual void v115(float);
};
#undef SLOT

struct Stage {
    char pad0[0x9c];
    int f9c;
    char padA0[0x100];
    void* f1a0;
};

extern "C" {
Ground* fn_50_32A4(int, const char*, const char*);
void addGround__5StageFP6Ground(Stage*, Ground*);
void createCollision__5StageFP9gfArchiveiP6Ground(Stage*, void*, int, Ground*);
}

extern "C" void fn_50_6A0(Stage* stage, int kind) {
    const float* rodata = (const float*)&lbl_50_rodata_0;
    const char* data = lbl_50_data_0;
    Ground* ground;
    float val;
    void* ptr;

    switch (kind) {
    case 1:
        ground = fn_50_32A4(1, data + 0x30, data + 0x48);
        val = rodata[1];
        ptr = (void*)((char*)stage + 0x1f0);
        break;
    case 2:
        ground = fn_50_32A4(1, data + 0x30, data + 0x58);
        val = rodata[2];
        ptr = (void*)((char*)stage + 0x1f0);
        break;
    case 3:
        ground = fn_50_32A4(1, data + 0x30, data + 0x68);
        val = rodata[3];
        ptr = (void*)((char*)stage + 0x1f0);
        break;
    case 4:
        ground = fn_50_32A4(1, data + 0x30, data + 0x78);
        val = rodata[4];
        ptr = (void*)((char*)stage + 0x208);
        break;
    case 5:
        ground = fn_50_32A4(1, data + 0x30, data + 0x88);
        val = rodata[5];
        ptr = (void*)((char*)stage + 0x208);
        break;
    case 6:
        ground = fn_50_32A4(1, data + 0x30, data + 0x98);
        val = rodata[6];
        ptr = (void*)((char*)stage + 0x208);
        break;
    default:
        ground = 0;
        break;
    }

    if (ground) {
        addGround__5StageFP6Ground(stage, ground);
        ground->v37(stage->f1a0, 0, 0);
        ground->v39(stage->f9c);
        createCollision__5StageFP9gfArchiveiP6Ground(stage, stage->f1a0, 3, ground);
        ground->v114(ptr);
        ground->v115(val);
    }
}
