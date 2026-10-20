#include <types.h>
#pragma force_active on

extern "C" {
void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
void fn_68_A004(void*, const char*);
extern char lbl_68_data_2BC0[];
}

struct NonPolyBase {
    char _0[0x3C];
};

#define DUMMY(n) virtual void dummy##n()

class GrFamicomGimmick : public NonPolyBase {
public:
    DUMMY(0); DUMMY(1); DUMMY(2); DUMMY(3); DUMMY(4); DUMMY(5); DUMMY(6); DUMMY(7); DUMMY(8); DUMMY(9);
    DUMMY(10); DUMMY(11); DUMMY(12); DUMMY(13); DUMMY(14); DUMMY(15); DUMMY(16); DUMMY(17); DUMMY(18); DUMMY(19);
    DUMMY(20); DUMMY(21); DUMMY(22); DUMMY(23); DUMMY(24); DUMMY(25); DUMMY(26); DUMMY(27); DUMMY(28); DUMMY(29);
    DUMMY(30); DUMMY(31); DUMMY(32); DUMMY(33); DUMMY(34); DUMMY(35); DUMMY(36); DUMMY(37); DUMMY(38); DUMMY(39);
    DUMMY(40); DUMMY(41);
    virtual void setMdlIndex(int mdlIndex);
    DUMMY(45); DUMMY(46); DUMMY(47); DUMMY(48); DUMMY(49); DUMMY(50); DUMMY(51); DUMMY(52); DUMMY(53); DUMMY(54);
    DUMMY(55); DUMMY(56); DUMMY(57); DUMMY(58); DUMMY(59); DUMMY(60); DUMMY(61); DUMMY(62); DUMMY(63); DUMMY(64);
    DUMMY(65); DUMMY(66); DUMMY(67); DUMMY(68); DUMMY(69); DUMMY(70); DUMMY(71); DUMMY(72); DUMMY(73); DUMMY(74);
    DUMMY(75); DUMMY(76); DUMMY(77); DUMMY(78); DUMMY(79);
    virtual void setTgtNode(const char* nodeName);
};

extern "C" void* fn_68_FFFC(int mdlIndex, const char* tgtNodeName, const char* taskName) {
    GrFamicomGimmick* obj = (GrFamicomGimmick*)__nw__FUlQ25Heaps8HeapType(0x1C4, 0xF);
    if (obj != 0) {
        fn_68_A004(obj, taskName);
        *(char**)((char*)obj + 0x3C) = lbl_68_data_2BC0;
        *(u8*)((char*)obj + 0x158) = 0xC;
        *(u8*)((char*)obj + 0x1C0) = 0;
    }
    if (obj != 0) {
        obj->setMdlIndex(mdlIndex);
        obj->setTgtNode(tgtNodeName);
    }
    return obj;
}
