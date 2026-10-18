#include <types.h>
#pragma force_active on

namespace StSeUtil {
    class SeSeq {
    public:
        virtual ~SeSeq() = 0;

        void* unk4;
        u32 unk8;
        void* unkC;
        u32 unk10;
        void* m_sndGenerator;
        s32 unk18;
        float unk1C;

        void playFrame(s32 unk, float frame);
        void playFrame(s32 unk2, float frame, float unk1);
    };

    void SeSeq::playFrame(s32 unk2, float frame, float unk1)
    {
        this->unk1C = unk1;
        this->playFrame(unk2, frame);
    }
}
