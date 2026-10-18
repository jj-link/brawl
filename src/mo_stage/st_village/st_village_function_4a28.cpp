#pragma force_active on
extern "C" {
extern char lbl_70_data_1298[];

void* GetResMat__Q34nw4r3g3d6ResMdlCFPCc(void*, const char*);
void* fn_8018D3F0(void*, const char*);
void fn_80192080(void*);
void fn_80192130(void*, void*, const char*);
void DCStore__Q34nw4r3g3d6ResMatFb(void*, bool);
}

extern "C" void fn_70_4A28(unsigned char* self, int state) {
    void* tex;
    char* data = lbl_70_data_1298;

    if (self[0x1c6] == (unsigned int)state)
        return;

    void* mdl = 0;
    void* mat = 0;
    tex = 0;

    void* obj = **(void***)(self + 0x44);
    if (!obj)
        return;

    mdl = *(void**)((unsigned char*)obj + 0xe8);
    if (!mdl)
        return;

    mat = GetResMat__Q34nw4r3g3d6ResMdlCFPCc(&mdl, data + 0x144);
    if (!mat)
        return;

    switch (state) {
    case 0:
        tex = fn_8018D3F0(self + 0x40, data + 0x148);
        break;
    case 1:
        tex = fn_8018D3F0(self + 0x40, data + 0x14c);
        break;
    case 2:
        tex = fn_8018D3F0(self + 0x40, data + 0x150);
        break;
    case 3:
        tex = fn_8018D3F0(self + 0x40, data + 0x154);
        break;
    case 4:
        tex = fn_8018D3F0(self + 0x40, data + 0x158);
        break;
    case 5:
        tex = fn_8018D3F0(self + 0x40, data + 0x15c);
        break;
    }

    if (tex) {
        fn_80192080(&mat);
        void* res = tex;
        fn_80192130(&mat, &res, data + 0x148);
        DCStore__Q34nw4r3g3d6ResMatFb(&mat, false);
        self[0x1c6] = state;
    }
}
