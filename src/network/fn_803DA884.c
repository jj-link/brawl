#include <revolution/VF/pf_cache.h>
#pragma force_active on

typedef struct CacheNode {
    char pad[0x1c];
    unsigned int owner;
    struct CacheNode *next;
} CacheNode;

extern int fn_803D9280(PF_VOLUME *, void *);

int PFCACHE_FlushDataCacheSpecific(PF_VOLUME *vol, int owner)
{
    int result = 0;
    CacheNode *head;
    CacheNode *node;
    if (*(unsigned int *)((char *)vol + 0x1624) & 7) {
        head = *(CacheNode **)((char *)vol + 0x1634);
        if (head->owner == 0 || head->owner == (unsigned int)owner) {
            result = fn_803D9280(vol, head);
            if (result != 0)
                return result;
        }
        node = head->next;
        while (node != head) {
            if (node->owner == 0 || node->owner == (unsigned int)owner) {
                result = fn_803D9280(vol, node);
                if (result != 0)
                    return result;
            }
            node = node->next;
        }
    }
    return result;
}