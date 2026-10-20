#include <types.h>
#pragma force_active on

struct FakeItem {
    char _[0x3d28];
    u32 m_field;
};

class FakeBase {
public:
    virtual ~FakeBase();
    virtual bool isNull() const;
};

class FakeList : public FakeBase {
public:
    virtual FakeItem*& at(s32 i);
    virtual s32 size() const;
};

struct FakeMgr {
    char _[0x6d8];
    FakeList m_list;
};

extern "C" int fn_27_2A8674(FakeMgr* self) {
    int count = 0;
    for (s32 i = 0; i < self->m_list.size(); i++) {
        FakeItem* item = self->m_list.at(i);
        if (item != NULL && item->m_field != (u32)-1) {
            count++;
        }
    }
    return count;
}
