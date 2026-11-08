#include <types.h>
#pragma force_active on

extern "C" {
extern const u8 lbl_27_data_71EB8[];
extern s32 lbl_27_data_71BF0[];
extern void* g_ftManager;
u32 fn_27_10A35C(void*);
}

struct Entry {
    u32 unused;
    u8 flag;
    u8 pad[3];
    s32 id;
    s32 group;
};

class EntryArray {
public:
    virtual void unused0();
    virtual void unused1();
    virtual Entry*& at(s32);
    virtual s32 size();
};

struct Context {
    u8 pad0[0xC8];
    EntryArray entries;
    u8 pad1[0x101D - 0xCC];
    u8 f101d;
    u8 pad2[0x1040 - 0x101E];
    u8 f1040;
    u8 pad3[0x10BC - 0x1041];
    s32 f10bc;
    u8 pad4[0x1494 - 0x10C0];
    u32 f1494;
    u8 pad5[0x14A0 - 0x1498];
    u8 f14a0;
};

class Object_vptr_3c_base {
public:
    char pad[0x3c];
};

class Object_vptr_3c : public Object_vptr_3c_base {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29();
    virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35(); virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39();
    virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43(); virtual void v44(); virtual void v45(); virtual void v46(); virtual void v47(); virtual void v48(); virtual void v49();
    virtual void v50(); virtual void v51(); virtual void v52(); virtual void v53(); virtual void v54(); virtual void v55(); virtual void v56(); virtual void v57(); virtual void v58(); virtual void v59();
    virtual void v60(); virtual void v61(); virtual void v62(); virtual void v63(); virtual void v64(); virtual void v65(); virtual void v66(); virtual void v67(); virtual void v68(); virtual void v69();
    virtual void v70(); virtual void v71(); virtual void v72(); virtual void v73(); virtual void v74(); virtual void v75(); virtual void v76(); virtual void v77(); virtual void v78(); virtual void v79();
    virtual void v80(); virtual void v81(); virtual void v82(); virtual void v83(); virtual void v84(); virtual void v85(); virtual void v86(); virtual void v87(); virtual void v88(); virtual void v89();
    virtual void v90(); virtual void v91(); virtual void v92(); virtual void v93(); virtual void v94(); virtual void v95(); virtual void v96(); virtual void v97(); virtual void v98(); virtual void v99();
    virtual void v100(); virtual void v101(); virtual void v102(); virtual void v103();
    virtual int v104();
};

extern "C" Object_vptr_3c* lbl_27_bss_5668;

static inline s32 query(Context* self) {
    if (self->f14a0 != 0) {
        if (lbl_27_data_71EB8[0xa1] == 0)
            return -1;
        switch (lbl_27_data_71BF0[0xa1]) {
        case 1:
        case 6:
        case 7:
            return 0xa1;
        }
    }
    return -1;
}

static inline Entry* find(Context* self, s32 id) {
    for (s32 i = 0; i < self->entries.size(); ++i) {
        Entry* entry = self->entries.at(i);
        if (entry != 0 && id == entry->id && entry->group == 0)
            return entry;
    }
    return 0;
}

static inline bool searchEntry(Context* self) {
    s32 id = 0xa1;
    if (query(self) >= 0)
        id = -3;
    return find(self, id) != 0;
}

extern "C" s32 fn_27_2A5BB4(Context* self, s32 arg1) {
    s32 result = 0;
    if ((s32)self->f1040 > 0) {
        result = 1;
    }
    if (arg1 != 0xa1) {
        if (self->f10bc == 0xa1 || (self->f10bc == -1 && searchEntry(self))) {
            result = 1;
        }
    }
    if (fn_27_10A35C(g_ftManager) == 1U) {
        result = 1;
    }
    if (arg1 == 0xa1 || arg1 == 0x37) {
        Object_vptr_3c* obj = lbl_27_bss_5668;
        if (obj != 0 && obj->v104() != 0) {
            result = 1;
        }
    }
    u32 flags = self->f1494;
    s32 cnt = 0;
    if (flags & 2) cnt = 1;
    if (flags & 4) cnt++;
    if (flags & 8) cnt++;
    if (self->f101d > cnt) cnt = self->f101d;
    if (arg1 == 0x14) {
        if ((flags & 0x10) || (cnt >= 2 && lbl_27_bss_5668 != 0 && lbl_27_bss_5668->v104() != 0)) {
            result = 1;
        } else if (cnt < 2) {
            result = 0;
        }
    } else if (cnt >= 3 || (flags & 0x10)) {
        result = 1;
    }
    return result;
}
