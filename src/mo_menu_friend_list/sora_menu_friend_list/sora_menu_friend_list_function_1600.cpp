#pragma force_active on

#include <types.h>
#include <mu/mu_msg.h>
#include <mu/mu_object.h>
#include <sr/sr_common.h>

extern "C" {
extern const f32 lbl_14_rodata_0[];

MuMsg* create__5MuMsgFUlQ25Heaps8HeapTypeUl(u32, HeapType, u32);
void FUN_800b9448__5MuMsgFUlb(MuMsg*, u32, bool);
void FUN_800b9460__5MuMsgFUlUcUcUcf(MuMsg*, u32, u8, u8, u8, f32);
void fn_800B9428(MuMsg*, u32, f32);
void fn_800B9488(MuMsg*, u32, u32);
}

#define ATTACH(index, object, bone) \
    msg->attachScnMdlSimple(index, static_cast<nw4r::g3d::ScnMdlSimple*>((object)->m_sceneModel), bone, ro[0x1e8 / 4])
#define COLOR(index, red, green, blue) msg->setFontColor(index, red, green, blue, 0xff)
#define SET_ALIGNMENT(index, mode) msg->setAlignMode(index, MuMsg::mode)
#define FONT(index) fn_800B9488(msg, index, 1)
#define WIDTH(index, offset) fn_800B9428(msg, index, ro[(offset) / 4])
#define EDGE(index, red, green, blue) \
    FUN_800b9448__5MuMsgFUlb(msg, index, true); \
    FUN_800b9460__5MuMsgFUlUcUcUcf(msg, index, red, green, blue, ro[0x1ec / 4])

static inline void resetColors(char* self) {
    for (int i = 0; i < 3; ++i) {
        (*reinterpret_cast<MuMsg**>(self + 0x24cc))->setFontColor(i + 0x18, 0xff, 0xff, 0xff, 0xff);
    }
}

static inline void setupHeader(MuMsg* msg, char* self, const f32* ro) {
    MuObject* object = *reinterpret_cast<MuObject**>(self + 0x8c);
    ATTACH(0, object, 0);
    COLOR(0, 0xff, 0xff, 0xff);
    SET_ALIGNMENT(0, Align_Left);
    EDGE(0, 0x4f, 0x3a, 0x3e);
    FONT(0);

    ATTACH(1, object, 1);
    COLOR(1, 0xac, 0x6d, 0x6d);
    SET_ALIGNMENT(1, Align_Left);
    FONT(1);

    ATTACH(2, object, 3);
    COLOR(2, 0xac, 0x6d, 0x6d);
    SET_ALIGNMENT(2, Align_Left);
    WIDTH(2, 0x1f0);
    FONT(2);
}

static inline void setupDetails(MuMsg* msg, char* self, const f32* ro) {
    MuObject* object = *reinterpret_cast<MuObject**>(self + 0xa4);
    ATTACH(0x14, object, 0);
    COLOR(0x14, 0, 0, 0);
    FONT(0x14);

    ATTACH(0x15, object, 1);
    COLOR(0x15, 0, 0, 0);

    ATTACH(0x16, object, 2);
    COLOR(0x16, 0x21, 0x60, 0xe0);
    FONT(0x16);
}

extern "C" void fn_14_1600(void* arg0, void* data) {
    MuMsg* msg;
    char* self = static_cast<char*>(arg0);
    const f32* ro = lbl_14_rodata_0;
    int index;
    char* base;
    MuObject* object;
    int i;

    msg = create__5MuMsgFUlQ25Heaps8HeapTypeUl(3, Heaps::MenuInstance, 0x2b);
    *reinterpret_cast<MuMsg**>(self + 0x24cc) = msg;
    msg->allocMsgBuf(0x100, 0x2c);
    msg->setMsgData(data);
    setupHeader(msg, self, ro);

    base = self;
    for (i = 0; i < 4; ++i) {
        object = *reinterpret_cast<MuObject**>(base + 0x54);

        index = i + 3;
        ATTACH(index, object, 0);
        COLOR(index, 0xff, 0xff, 0xff);
        SET_ALIGNMENT(index, Align_Left);
        EDGE(index, 0x3f, 0x3a, 0x4f);
        FONT(index);

        index = i + 7;
        ATTACH(index, object, 2);
        SET_ALIGNMENT(index, Align_Left);

        index = i + 0xb;
        ATTACH(index, object, 3);
        SET_ALIGNMENT(index, Align_Left);
        FONT(index);

        index = i + 0xf;
        ATTACH(index, object, 4);
        SET_ALIGNMENT(index, Align_Right);
        COLOR(index, 0x21, 0x60, 0xe0);
        FONT(index);

        base += 4;
    }

    ATTACH(0x13, *reinterpret_cast<MuObject**>(self + 0xac), 0);
    COLOR(0x13, 0xe7, 0xe4, 0xe7);
    FONT(0x13);

    setupDetails(msg, self, ro);
    object = *reinterpret_cast<MuObject**>(self + 0xb0);
    ATTACH(0x17, object, 0);
    COLOR(0x17, 0xf2, 0x4d, 0x4d);
    FONT(0x17);

    for (index = 0; index < 3; ++index) {
        i = index + 0x18;
        ATTACH(i, object, index + 1);
        SET_ALIGNMENT(i, Align_Left);
        FONT(i);
        WIDTH(i, 0x1f4);
    }

    resetColors(self);
    ATTACH(0x1b, object, 4);
    COLOR(0x1b, 0xff, 0xff, 0xff);
    SET_ALIGNMENT(0x1b, Align_Left);
    WIDTH(0x1b, 0x1f4);
    FONT(0x1b);

    object = *reinterpret_cast<MuObject**>(self + 0xb8);
    index = 0;
    do {
        i = index + 0x1c;
        ATTACH(i, object, index);
        COLOR(i, 0x57, 0x57, 0x57);
        FONT(i);
    } while (++index < 10);

    object = *reinterpret_cast<MuObject**>(self + 0xc4);
    index = 0;
    do {
        i = index + 0x26;
        ATTACH(i, object, index);
        COLOR(i, 0x4f, 0x3a, 0x3e);
        SET_ALIGNMENT(i, Align_Left);
        FONT(i);
        WIDTH(i, 0x1f8);
    } while (++index < 4);

    ATTACH(0x2a, object, 4);

    ATTACH(0x2b, *reinterpret_cast<MuObject**>(self + 0x194), 0);
    FONT(0x2b);
    SET_ALIGNMENT(0x2b, Align_Left);
    WIDTH(0x2b, 0x1fc);
}