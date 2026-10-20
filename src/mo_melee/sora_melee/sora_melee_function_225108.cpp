#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;
typedef int s32;

struct SndID {
    u32 id;
};

struct SeSeqEntry {
    u32 id;
    s32 f4;
    u32 f8;
    u32 fc;
};

extern "C" void fn_27_22520C();

namespace StSeUtil {
class SeSeq {
public:
    void registId(SndID* ids, unsigned long n);
    u8 pad[0xc];
    SeSeqEntry* m_0c;
    u32 m_10;
};
}

void StSeUtil::SeSeq::registId(SndID* ids, unsigned long n) {
    for (u32 i = 0; i < m_10; i++) {
        if (i < n) {
            m_0c[i].id = ids->id;
        } else {
            m_0c[i].id = -1;
        }
        m_0c[i].f4 = -1;
        m_0c[i].f8 = 0;
        m_0c[i].fc = 0;
        ids++;
    }
    fn_27_22520C();
}
