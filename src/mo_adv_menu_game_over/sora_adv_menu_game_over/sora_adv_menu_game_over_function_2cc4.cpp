#include <mu/mu_object.h>
#include <mu/mu_msg.h>
#include <gf/gf_3d_scene.h>
#include <string.h>
#include <stdio.h>
#pragma force_active on

struct Name { char s[65]; };
struct Triple { unsigned long v[3]; };
struct Menu {
    char pad[0x1b4];
    int value;
    unsigned long text[3];
    char pad1c4[4];
    nw4r::g3d::ResFile res;
    void* msgData;
    MuObject* object;
    MuMsg* msg;
};

extern "C" {
extern char lbl_33_data_3F4[];
extern char lbl_33_data_3E4[];
extern char lbl_33_data_3E0[];
extern Triple lbl_33_data_408;
extern Triple lbl_33_data_414;
extern const float lbl_33_rodata_A0;
extern const float lbl_33_rodata_A4;
int fn_8018D108(void*, const char*);
void fn_800B8A0C(MuMsg*, int);
MuMsg* create__5MuMsgFUlQ25Heaps8HeapTypeUl(unsigned long, HeapType, unsigned long);
}

extern "C" void fn_33_2CC4(Menu* self) {
    int value;
    Menu* entry;
    unsigned long j;
    int i;
    unsigned long* bone;
    unsigned long* id;
    const char* name = lbl_33_data_3F4;
    if (fn_8018D108(&self->res, name)) {
        MuObject* object = MuObject::create(&self->res, name, 16, 0, (HeapType)42);
        if (self->object != object) {
            delete self->object;
            self->object = object;
        }
        g_gfSceneRoot->add(gfSceneRoot::Layer_Info, self->object->m_sceneModel);

        MuObject* obj = self->object;
        char* mdl = *(char**)((char*)obj + 8);
        int off = *(int*)(mdl + 0x3c);
        const char* src = off ? mdl + off : 0;
        Name n;
        n.s[0] = 0;
        strcat(n.s, src);
        Name n2 = n;
        strcat(n2.s, lbl_33_data_3E4);
        Name n3 = n2;
        sprintf(n3.s + strlen(n3.s), lbl_33_data_3E0, 0);
        Name n4 = n3;
        obj->changeNodeAnimNIf(n4.s);

        obj = self->object;
        mdl = *(char**)((char*)obj + 8);
        off = *(int*)(mdl + 0x3c);
        src = off ? mdl + off : 0;
        Name n5;
        n5.s[0] = 0;
        strcat(n5.s, src);
        Name n6 = n5;
        strcat(n6.s, lbl_33_data_3E4);
        Name n7 = n6;
        sprintf(n7.s + strlen(n7.s), lbl_33_data_3E0, 0);
        Name n8 = n7;
        obj->changeVisAnimNIf(n8.s);

        obj = self->object;
        mdl = *(char**)((char*)obj + 8);
        off = *(int*)(mdl + 0x3c);
        src = off ? mdl + off : 0;
        Name n9;
        n9.s[0] = 0;
        strcat(n9.s, src);
        Name n10 = n9;
        strcat(n10.s, lbl_33_data_3E4);
        Name n11 = n10;
        sprintf(n11.s + strlen(n11.s), lbl_33_data_3E0, 0);
        Name n12 = n11;
        obj->changeClrAnimNIf(n12.s);

        self->object->m_modelAnim->m_anmObjMatClrRes->SetUpdateRate(lbl_33_rodata_A0);
        value = self->value;
        self->object->setFrameMatCol((float)(int)(value != 0));
        self->value = value;

        MuMsg* msg = create__5MuMsgFUlQ25Heaps8HeapTypeUl(1, (HeapType)42, 43);
        if (self->msg != msg) {
            fn_800B8A0C(self->msg, 1);
            self->msg = msg;
        }
        self->msg->allocMsgBuf(256, 3);
        self->msg->setMsgData(self->msgData);
        Triple bones;
        Triple ids = lbl_33_data_408;
        bones = lbl_33_data_414;
        bone = bones.v;
        id = ids.v;
        for (i = 0; i < 3; ++i, ++bone, ++id) {
            self->msg->attachScnMdlSimple(*id, self->object->m_sceneModel, *bone, lbl_33_rodata_A4);
            self->msg->setAlignMode(*id, MuMsg::Align_Center);
            self->msg->setFontColor(*id, 0, 0, 0, 255);
        }
        entry = self;
        for (j = 0; (int)j < 3; ++j, entry = (Menu*)((char*)entry + 4)) {
            self->msg->printIndex(j, entry->text[0], 0);
        }
    }
}
