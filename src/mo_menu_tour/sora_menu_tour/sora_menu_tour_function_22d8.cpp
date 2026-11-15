#include <types.h>
#include <gf/gf_archive.h>
#include <gf/gf_heap_manager.h>
#include <mu/mu_object.h>
#include <mu/mu_msg.h>
#include <nw4r/g3d/g3d_scnmdl.h>
#include <string.h>
#pragma force_active on
extern char lbl_3_data_0[];
extern const float lbl_3_rodata_8120;
extern const float lbl_3_rodata_8158;
extern "C" void fn_800B5854(void*, int, int, int, int);
extern "C" void fn_800B9488(MuMsg*, u32, int);

struct AnmObjFake {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void setFrame(float);
};
static void setFrameMatCol(MuObject* obj) {
    ((AnmObjFake*)obj->m_modelAnim->m_anmObjMatClrRes)->setFrame(lbl_3_rodata_8120);
}
struct TourData {
    nw4r::g3d::ScnMdl* scnMdl;
    MuObject* lineObjs[63];
    MuObject* stcObjs[31];
    void* stcRes[31];
    void* lineRes[63];
    char pad2F4[4];
    int priority;
    char pad2FC[0xF50 - 0x2FC];
    MuObject* msgObjs[32];
    MuObject* msgObjs2[32];
    MuObject* msgObjs3[32];
    void* resFile3;
    MuMsg* msg;
    nw4r::g3d::ResFile* msgRes;
    void* resFile4;
    u8 flag1;
    u8 flag2;
    char pad10E2[2];
    gfArchive* archive;
    gfFileIOHandle fileIO;
};
extern "C" s32 fn_3_22D8(TourData* self) {
    char* base = lbl_3_data_0;
    u8 flag1 = self->flag1;
    if (flag1 != 0 && self->flag2 != 0) goto done;
    if (flag1 == 0) {
        if (!self->archive->unk9) return 0;
        self->flag1 = 1;
    }
    if (self->flag2 == 0 && self->fileIO.m_request != 0) {
        if (!self->fileIO.isReady()) return 0;
        self->flag2 = 1;
    }
    int size;
    void* buf;
    void* lineData;
    u32 i;
    lineData = self->archive->getData(Data_Type_Model, 0, &size, 0xFFFE);
    self->lineRes[0] = lineData;
    nw4r::g3d::ResFile::Init(&self->lineRes[0]);
    self->lineObjs[0] = MuObject::create((nw4r::g3d::ResFile*)&self->lineRes[0], base + 0x40, self->priority, 0, (HeapType)0x2A);
    self->lineObjs[0]->changeClrAnimNIf(base + 0x8C);
    setFrameMatCol(self->lineObjs[0]);
    for (i = 1; i < 0x3F; i++) {
        buf = gfHeapManager::alloc((HeapType)0x2B, size);
        memcpy(buf, lineData, size);
        self->lineRes[i] = buf;
        nw4r::g3d::ResFile::Init(&self->lineRes[i]);
        self->lineObjs[i] = MuObject::create((nw4r::g3d::ResFile*)&self->lineRes[i], base + 0x40, self->priority, 0, (HeapType)0x2A);
        self->lineObjs[i]->changeClrAnimNIf(base + 0x8C);
        setFrameMatCol(self->lineObjs[i]);
    }
    u32 j;
    void* stcData;
    buf = self->archive->getData(Data_Type_Model, 1, &size, 0xFFFE);
    self->stcRes[0] = buf;
    nw4r::g3d::ResFile::Init(&self->stcRes[0]);
    self->stcObjs[0] = MuObject::create((nw4r::g3d::ResFile*)&self->stcRes[0], base + 0xA4, self->priority, 0, (HeapType)0x2A);
    self->stcObjs[0]->changeClrAnimNIf(base + 0xB8);
    setFrameMatCol(self->stcObjs[0]);
    for (j = 1; j < 0x1F; j++) {
        stcData = gfHeapManager::alloc((HeapType)0x2B, size);
        memcpy(stcData, buf, size);
        self->stcRes[j] = stcData;
        nw4r::g3d::ResFile::Init(&self->stcRes[j]);
        self->stcObjs[j] = MuObject::create((nw4r::g3d::ResFile*)&self->stcRes[j], base + 0xA4, self->priority, 0, (HeapType)0x2A);
        self->stcObjs[j]->changeClrAnimNIf(base + 0xB8);
        setFrameMatCol(self->stcObjs[j]);
    }
    void* msgData = self->archive->getData(Data_Type_Model, 2, 0xFFFE);
    self->resFile3 = msgData;
    nw4r::g3d::ResFile::Init(&self->resFile3);
    self->resFile4 = 0;
    if (self->msgRes == 0) {
        self->resFile4 = self->fileIO.getBuffer();
        nw4r::g3d::ResFile::Init(&self->resFile4);
        self->msgRes = (nw4r::g3d::ResFile*)&self->resFile4;
    }
    for (int i = 0; i < 0x20; i++) {
        self->msgObjs[i] = MuObject::create((nw4r::g3d::ResFile*)&self->resFile3, base + 0xD0, self->priority + 1, 0, (HeapType)0x2A);
        self->msgObjs2[i] = MuObject::create((nw4r::g3d::ResFile*)&self->resFile3, base + 0xE4, self->priority + 2 + (i % 2), self->msgRes, (HeapType)0x2A);
        self->msgObjs3[i] = MuObject::create((nw4r::g3d::ResFile*)&self->resFile3, base + 0xF8, self->priority + 4, 0, (HeapType)0x2A);
        fn_800B5854(self->msgObjs3[i], 0, 2, 0, 0);
    }
    for (int i = 0; i < 0x20; i++) {
        self->msg->attachScnMdlSimple(i, self->msgObjs[i]->m_sceneModel, 0, lbl_3_rodata_8158);
        self->msg->setAlignMode(i, MuMsg::Align_Left);
        self->msg->setFontWidthModeAuto(i);
        fn_800B9488(self->msg, i, 1);
        self->msg->setFontColor(i, 0, 0, 0, 0xFF);
    }
    self->scnMdl = nw4r::g3d::ScnMdl::Construct(gfHeapManager::getMEMAllocator((HeapType)0x2A), (int)&size, 0xBE, self->lineObjs[0]->m_scnMdl);
done:
    return 1;
}