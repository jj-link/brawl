#pragma force_active on

extern "C" {
    extern void* g_ecMgr;
    extern void* g_sndSystem;
    extern float lbl_27_rodata_61C8;
    extern float lbl_27_rodata_61E8;
    
    void playSE__9sndSystemF5SndIDiiii(void*, int, int, int, int, int);
    void setMdlFrame__5ecMgrFUlfSc(void*, int, float, int);
}

struct Base {
    unsigned char pad0[0x28];
    virtual void v0();
    virtual void v1();
};

extern "C" int fn_27_2D60B8(Base* self, int arg1, int flags) {
    (void)arg1;
    int* obj = (int*)self;
    void* ecMgr = g_ecMgr;
    
    if (obj[0] != 1) return -3;
    
    if (flags & obj[9]) {
        self->v1();
        if (obj[7] >= 0) {
            return obj[2];
        }
        return -2;
    }
    
    if (flags & 0x200) {
        self->v1();
        return -2;
    }
    
    if (obj[7] >= 0) {
        if (flags & 1) {
            if (obj[2] != 1) {
                obj[2] = 1;
                playSE__9sndSystemF5SndIDiiii(g_sndSystem, 0, -1, 0, 0, -1);
            }
            setMdlFrame__5ecMgrFUlfSc(ecMgr, obj[3], lbl_27_rodata_61E8, 0x10);
        } else if (flags & 2) {
            if (obj[2] != -1) {
                obj[2] = -1;
                playSE__9sndSystemF5SndIDiiii(g_sndSystem, 0, -1, 0, 0, -1);
            }
            setMdlFrame__5ecMgrFUlfSc(ecMgr, obj[3], lbl_27_rodata_61C8, 0x10);
        }
    }
    
    return 0;
}
