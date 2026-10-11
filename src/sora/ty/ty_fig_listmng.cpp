#include <cstdio>
#include <gf/gf_heap_manager.h>
#include <gm/gm_lib.h>
#include <memory.h>
#include <stddef.h>
#include <ty/ty_fig_listmng.h>
#include <ut/ut_relocate.h>

tyFigListDataManager::tyFigListDataManager(bool loadFile) :
        m_isLoaded(false), m_isUnloaded(true) {
    if (loadFile) {
        loadRequest();
    }
}

tyFigListDataManager::~tyFigListDataManager() {
    if (!m_isUnloaded) {
        gfHeapManager::free(m_fileHandle.getBuffer());
        m_fileHandle.release();
    }
}

bool tyFigListDataManager::loadRequest() {
    if (m_isLoaded) {
        return false;
    }
    m_isLoaded = false;
    m_isUnloaded = false;
    m_fileHandle.read("/toy/fig/ty_fig_data.dat", Heaps::ItemResource, 0);
    setData(m_fileHandle.getBuffer(), m_fileHandle.getSize());
    m_isLoaded = true;
    return true;
}

bool tyFigListDataManager::isLoadFinish() {
    if (!m_isLoaded) {
        if (!m_fileHandle.isReady()) {
            return false;
        }
        setData(m_fileHandle.getBuffer(), m_fileHandle.getSize());
        m_isLoaded = true;
        return true;
    }
    return true;
}

void tyFigListDataManager::setData(void* fileBuf, u32 fileSz) {
    utRelocate object(reinterpret_cast<u8*>(fileBuf), fileSz);
    m_data = static_cast<tyFigListData*>(object.getPublicAddress("tyDataList"));
    m_count = 0;
    while (m_data[m_count].id >= 0) {
        m_count++;
    }

    // Byte cursors traverse the enclosing object, not before either array.
    u8* bySeries = reinterpret_cast<u8*>(this);
    u32 seriesOffset;
    for (u32 i = 0; i < 22; i++) {
        u32 j = 0;
        seriesOffset = 0;
        for (; j < m_count; seriesOffset += sizeof(tyFigListData), j++) {
            if (i == reinterpret_cast<tyFigListData*>(reinterpret_cast<u8*>(m_data) + seriesOffset)->series) {
                *reinterpret_cast<u32*>(bySeries + offsetof(tyFigListDataManager, m_bySeries)) = j;
                bySeries += sizeof(u32);
            }
        }
    }

    u8* byKind = reinterpret_cast<u8*>(this);
    u32 kindOffset;
    for (u32 i = 23; i < 33; i++) {
        u32 j = 0;
        kindOffset = 0;
        for (; j < m_count; kindOffset += sizeof(tyFigListData), j++) {
            if (i == reinterpret_cast<tyFigListData*>(reinterpret_cast<u8*>(m_data) + kindOffset)->kind) {
                *reinterpret_cast<u32*>(byKind + offsetof(tyFigListDataManager, m_byKind)) = j;
                byKind += sizeof(u32);
            }
        }
    }
    m_isLoaded = true;
}

u32 tyFigListDataManager::getFigListSeries(s32 series, u32 pageNum, u32* figList) {
    u32* lst;
    u32 lstSize = 0;
    u32 total = 0;
    u32 start = pageNum * TrophiesPerPage;

    if (!m_isLoaded) {
        return 0;
    }

    lst = figList;
    for (u32 i = 0; i < m_count && lstSize < TrophiesPerPage; i++) {
        tyFigListData* fig = m_data + i;
        if (series == fig->series && gmCheckExistFigure(fig->id) == true && ++total > start) {
            *lst++ = i;
            lstSize++;
        }
    }
    return lstSize;
}

/**
 * Get the number of pages of existing trophies belonging
 * to the specified series
 */
u32 tyFigListDataManager::getPageNumSeries(s32 series) {
    u32 n = 0;
    if (!m_isLoaded) {
        return 0;
    }

    for (u32 i = 0; i < m_count; i++) {
        tyFigListData* fig = m_data + i;
        if (series == fig->series && gmCheckExistFigure(fig->id) == true) {
            n++;
        }
    }

    return (n % TrophiesPerPage == 0) ? n / TrophiesPerPage : n / TrophiesPerPage + 1;
}

/**
 * Given a trophy ID, return the ID of the next acquired trophy that would appear
 * in the "By Series" ordering
 */
u32 tyFigListDataManager::nextIdSeries(u32 id) {
    if (!m_isLoaded) {
        return 0;
    }

    u32 next;
    for (next = 0; next < m_count; next++) {
        if (id == m_bySeries[next]) {
            if (++next >= m_count) {
                next = 0;
            }
            break;
        }
    }

    u32 start = next;
    for (u32 i = 0; i < m_count; i++) {
        tyFigListData* fig = m_data;
        u32 j = (start + i) % m_count;
        if (gmCheckExistFigure(fig[m_bySeries[j]].id) == true) {
            return m_bySeries[j];
        }
    }

    return id;
}

u32 tyFigListDataManager::prevIdSeries(u32 id) {
    if (!m_isLoaded) {
        return 0;
    }

    s32 prev;
    for (prev = 0; prev < m_count; prev++) {
        if (id == m_bySeries[prev]) {
            if (--prev < 0) {
                prev = m_count - 1;
            }
            break;
        }
    }

    for (u32 i = 0; i < m_count; i++) {
        u32 j = m_count - (i - prev);
        if (prev >= i) {
            j = prev - i;
        }
        if (gmCheckExistFigure(m_data[m_bySeries[j]].id) == true) {
            return m_bySeries[j];
        }
    }

    return id;
}

u32 tyFigListDataManager::getFigListKind(s32 kind, u32 pageNum, u32* figList) {
    u32* lst;
    u32 lstSize = 0;
    u32 total = 0;
    u32 start = pageNum * TrophiesPerPage;

    if (!m_isLoaded) {
        return 0;
    }

    lst = figList;
    for (u32 i = 0; i < m_count && lstSize < TrophiesPerPage; i++) {
        tyFigListData* fig = m_data + i;
        if (kind == fig->kind && gmCheckExistFigure(fig->id) == true && ++total > start) {
            *lst++ = i;
            lstSize++;
        }
    }
    return lstSize;
}

/**
 * Get the number of pages of existing trophies belonging
 * to the specified kind.
 */
u32 tyFigListDataManager::getPageNumKind(s32 kind) {
    u32 n = 0;

    if (!m_isLoaded) {
        return 0;
    }
    for (u32 i = 0; i < m_count; i++) {
        tyFigListData* fig = m_data + i;
        if (kind == fig->kind && gmCheckExistFigure(fig->id) == true) {
            n++;
        }
    }

    return (n % TrophiesPerPage == 0) ? n / TrophiesPerPage : n / TrophiesPerPage + 1;
}

u32 tyFigListDataManager::nextIdKind(u32 id) {
    if (!m_isLoaded) {
        return 0;
    }

    u32 next;
    for (next = 0; next < m_count; next++) {
        if (id == m_byKind[next]) {
            if (++next >= m_count) {
                next = 0;
            }
            break;
        }
    }

    for (u32 i = 0; i < m_count; i++) {
        u32 j = (next + i) % m_count;
        if (gmCheckExistFigure(m_data[m_byKind[j]].id) == true) {
            return m_byKind[j];
        }
    }

    return id;
}

u32 tyFigListDataManager::prevIdKind(u32 id) {
    if (!m_isLoaded) {
        return 0;
    }

    s32 prev;
    for (prev = 0; prev < m_count; prev++) {
        if (id == m_byKind[prev]) {
            if (--prev < 0) {
                prev = m_count - 1;
            }
            break;
        }
    }

    for (u32 i = 0; i < m_count; i++) {
        u32 j = m_count - (i - prev);
        if (prev >= i) {
            j = prev - i;
        }
        if (gmCheckExistFigure(m_data[m_byKind[j]].id) == true) {
            return m_byKind[j];
        }
    }

    return id;
}

/**
 * Get the total number of collected trophies that come before id in
 * the ordering specified in 'orderBySeries' (if false, order by kind)
 */
u32 tyFigListDataManager::getTotalId(u32 id, bool orderBySeries) {
    if (!m_isLoaded) {
        return 0;
    }

    if (orderBySeries) {
        u32 total = 0;
        for (u32 i = 0; i < m_count; i++) {
            if (gmCheckExistFigure(m_data[m_bySeries[i]].id) == true) {
                total++;
                if (id == m_bySeries[i]) {
                    return total;
                }
            }
        }
    } else {
        u32 total = 0;
        for (u32 i = 0; i < m_count; i++) {
            if (gmCheckExistFigure(m_data[m_byKind[i]].id) == true) {
                total++;
                if (id == m_byKind[i]) {
                    return total;
                }
            }
        }
    }
    return id;
}

s32 tyFigListDataManager::getBilTexFileIdx(u32 i) {
    if (!m_isLoaded) {
        return -1;
    }
    return m_data[i].bilTexIdx / 10;
}

s32 tyFigListDataManager::getBilTexFileIdxFigId(u16 id) {
    if (!m_isLoaded) {
        return -1;
    }
    tyFigListData* fig = getFigDataId(id);
    return (!fig) ? -1 : fig->bilTexIdx / 10;
}

void tyFigListDataManager::getBilTexFileNameFigId(u16 id, char* name) {
    sprintf(name, "/toy/figdisp/figdisp%03d.brres", getBilTexFileIdxFigId(id)*10);
}

void tyFigListDataManager::getBilTexName(u32 i, char* name) {
    sprintf(name, "MenCollDisply01.%03d", m_data[i].bilTexIdx);
}

void tyFigListDataManager::getBilTexNameFigId(u32 id, char* name) {
    sprintf(name, "MenCollDisply01.%03d", getFigDataId(id)->bilTexIdx);
}

tyFigListData* tyFigListDataManager::getFigDataId(u32 id) {
    if (!m_isLoaded) {
        return 0;
    }

    for (u32 i = 0; i < m_count; i++) {
        if (id == m_data[i].id) {
            return &m_data[i];
        }
    }
    return 0;
}
