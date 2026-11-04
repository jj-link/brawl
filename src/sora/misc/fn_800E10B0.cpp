#include <ms/ms_message.h>
#include <gf/gf_camera.h>
#include <gf/gf_heap_manager.h>
#pragma force_active on

extern "C" {
void fn_80018610(void*);
void fn_8006BCA8(char*, const unsigned short*);
void fn_80069D08(Message*, unsigned char);
void fn_8006A170(Message*, int);
void fn_8007270C(void*, void*, int, int, float, float, float, float);
unsigned char fn_800B8648(void*, int, int, int);
void fn_800B881C(void*, unsigned char);
extern unsigned char lbl_8049E01C[0x14];
extern float lbl_805A23B0;
extern float lbl_805A23D0;
extern float lbl_805A23D4;
extern float lbl_805A23D8;
extern float lbl_805A23DC;
extern float lbl_805A23E0;
}

extern "C" int fn_800E10B0(void* arg0, const unsigned short* arg1, int arg2, int* arg3, int arg4, int arg5, int arg6, void* arg7, int arg8) {
    gfCamera camera;
    Message msg(0x80, (HeapType)0x2a);
    fn_80018610(&camera);
    camera.m_projectionType = gfCamera::Projection_Orthogonal;
    *(float*)((char*)&camera + 0x114) = lbl_805A23B0;
    *(float*)((char*)&camera + 0x118) = lbl_805A23B0;
    *(float*)((char*)&camera + 0x11c) = lbl_805A23D0;
    *(float*)((char*)&camera + 0x120) = lbl_805A23D4;
    *(float*)((char*)&camera + 0x124) = lbl_805A23B0;
    *(float*)((char*)&camera + 0x128) = lbl_805A23D8;
    *(short*)((char*)&camera + 0x12c) = 0;
    *(short*)((char*)&camera + 0x12e) = 0;
    *(short*)((char*)&camera + 0x130) = 640;
    *(short*)((char*)&camera + 0x132) = 480;
    camera.setGX();
    Message::drawBoxLine(*arg3, 0, 1, lbl_805A23B0, lbl_805A23B0, (float)arg5, (float)arg6, lbl_805A23B0);
    int len;
    unsigned char old = fn_800B8648(&lbl_8049E01C, 2, 255, 0);
    const unsigned short* p = arg1;
    len = 0;
    while (*p) {
        ++p;
        ++len;
    }
    char* buf = (char*)gfHeapManager::alloc((HeapType)0x2a, len * 4 + 1);
    fn_8006BCA8(buf, arg1);
    msg.changeMsgBuf(-1);
    msg.clearMsgBuf();
    msg.setCallProjection(0);
    msg.setWindow(lbl_805A23B0, lbl_805A23B0, (float)arg5, (float)arg6);
    if (arg4) {
        msg.setDrawFlag(0x100, 0x300);
        msg.setDrawFlag(1, 3);
    } else {
        msg.setDrawFlag(0, 0x300);
        msg.setDrawFlag(0, 3);
    }
    msg.setScale((float)arg8 * lbl_805A23DC);
    msg.setFixedWidth(lbl_805A23E0);
    fn_80069D08(&msg, 1);
    fn_8006A170(&msg, arg2);
    msg.setFace(2);
    msg.printf(buf);
    gfHeapManager::free(buf);
    msg.printMsgBuf((FontData::FONT_RESOURCE)2);
    fn_8007270C(arg0, arg7, 0x2a, 1, lbl_805A23B0, lbl_805A23B0, (float)arg5, (float)arg6);
    fn_800B881C(&lbl_8049E01C, old);
    return len;
}