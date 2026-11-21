#include <mu/mu_msg.h>
#pragma force_active on

extern "C" {
extern const float lbl_9_rodata_0[];
MuMsg* create__5MuMsgFUlQ25Heaps8HeapTypeUl(unsigned long, HeapType, unsigned long);
void* fn_80015DB4(void*, int, int, int, unsigned short);
void fn_800B93DC(MuMsg*, unsigned long, int);
void fn_800B9428(MuMsg*, unsigned long, float);
void fn_800B9488(MuMsg*, unsigned long, int);
}

#define MODEL(p, o) \
    (*reinterpret_cast<nw4r::g3d::ScnMdlSimple**>( \
        *reinterpret_cast<char**>((p) + (o)) + 0x10))

extern "C" void fn_9_AF0(char* self) {
    const float* ro = lbl_9_rodata_0;
    char* obj;
    char* p;
    int i;
    MuMsg* msg = create__5MuMsgFUlQ25Heaps8HeapTypeUl(3, (HeapType)42, 43);

    *reinterpret_cast<MuMsg**>(self + 0x17c0) = msg;
    msg->allocMsgBuf(0x200, 0x12);
    msg->setMsgData(fn_80015DB4(
        *reinterpret_cast<void**>(self + 0x17f0), 0, 1, 30,
        (unsigned short)0xfffe));

    obj = *reinterpret_cast<char**>(self + 0x44);
    msg->attachScnMdlSimple(
        0, *reinterpret_cast<nw4r::g3d::ScnMdlSimple**>(obj + 0x10),
        0, ro[0x9c / 4]);
    msg->setFontColor(0, 0, 0, 0, 255);
    fn_800B93DC(msg, 0, 1);

    msg->attachScnMdlSimple(
        1, *reinterpret_cast<nw4r::g3d::ScnMdlSimple**>(obj + 0x10),
        1, ro[0x9c / 4]);
    msg->setFontColor(1, 30, 30, 30, 255);
    fn_800B9428(msg, 1, ro[0xa0 / 4]);
    msg->setAlignMode(1, MuMsg::Align_Left);

    msg->attachScnMdlSimple(
        2, *reinterpret_cast<nw4r::g3d::ScnMdlSimple**>(obj + 0x10),
        2, ro[0x9c / 4]);
    msg->setFontColor(2, 190, 177, 137, 255);
    msg->setAlignMode(2, MuMsg::Align_Left);

    msg->attachScnMdlSimple(
        3, *reinterpret_cast<nw4r::g3d::ScnMdlSimple**>(obj + 0x10),
        3, ro[0x9c / 4]);
    msg->setFontColor(3, 250, 250, 250, 255);
    msg->getHScale(3, ro[0xa4 / 4]);
    msg->getWScale(3, ro[0xa8 / 4]);

    p = self;
    for (i = 0; i < 11; ++i, p += 4) {
        msg->attachScnMdlSimple(i + 4, MODEL(p, 0x4c), 0, ro[0x9c / 4]);
        msg->setFontColor(i + 4, 250, 250, 250, 255);
        fn_800B9488(msg, i + 4, 1);
    }

    msg->attachScnMdlSimple(16, MODEL(self, 0x188), 0, ro[0x9c / 4]);
    msg->setFontColor(16, 0, 0, 0, 255);
    msg->attachScnMdlSimple(17, MODEL(self, 0x18c), 0, ro[0x9c / 4]);
    msg->setFontColor(17, 0, 0, 0, 255);
}
