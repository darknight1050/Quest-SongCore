#pragma once

#include "custom-types/shared/macros.hpp"
#include "GlobalNamespace/BeatmapLevelsRepository.hpp"
#include "CustomLevelPack.hpp"
#include <span>

DECLARE_CLASS_CODEGEN(SongCore::SongLoader, CustomBeatmapLevelsRepository, GlobalNamespace::BeatmapLevelsRepository,
    DECLARE_CTOR(ctor);
        DECLARE_INSTANCE_FIELD_PRIVATE(ListW<GlobalNamespace::BeatmapLevelPack*>, _levelPacks);
    public:
        void AddLevelPack(GlobalNamespace::BeatmapLevelPack* pack);
        void RemoveLevelPack(GlobalNamespace::BeatmapLevelPack* pack);
        void ClearLevelPacks();

        std::span<GlobalNamespace::BeatmapLevelPack* const> GetBeatmapLevelPacks() const { return _levelPacks; }
        __declspec(property(get=GetBeatmapLevelPacks)) std::span<GlobalNamespace::BeatmapLevelPack* const> BeatmapLevelPacks;
)