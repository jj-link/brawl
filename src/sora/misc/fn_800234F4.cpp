#include <gf/gf_file_io_manager.h>
#pragma force_active on

extern "C" int fn_80044248(void*);
extern "C" int fn_80044360(void*);

struct BitSet {
    int size;
    unsigned int words[1];
};

struct RequestPool {
    int unk0;
    BitSet* bits;
    gfFileIORequest* requests;
};

struct TopTwoBits {
    unsigned char clear : 2;
    unsigned char rest : 6;
};
struct LowSevenBits {
    unsigned char rest : 1;
    unsigned char clear : 7;
};
struct RequestState {
    unsigned int upper : 12;
    unsigned int state : 8;
    unsigned int lower : 12;
};

static inline gfFileIORequest* initRequest(gfFileIORequest* request)
{
    if (request) {
        unsigned char* p = (unsigned char*)request;
        ((TopTwoBits*)(p + 0x16))->clear = 0;
        ((LowSevenBits*)(p + 0x17))->clear = 0;
        ((TopTwoBits*)(p + 0x18))->clear = 0;
        ((RequestState*)(p + 0x18))->state = 1;
        request->m_notifyCallback = 0;
    }
    return request;
}

gfFileIORequest* gfFileIOManager::allocRequest()
{
    RequestPool* pool = *(RequestPool**)_0x10;
    gfFileIORequest* request;
    if (fn_80044248(pool->bits)) {
        int index = fn_80044360(pool->bits);
        pool->bits->words[index >> 5] |= 1 << (index & 31);
        request = &pool->requests[index];
    } else {
        request = 0;
    }
    gfFileIORequest* result = 0;
    if (request) {
        result = initRequest(request);
    }
    return result;
}
