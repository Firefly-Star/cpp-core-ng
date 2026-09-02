#include "srs/engine/battle_engine.hpp"

#include <stdexcept>

namespace srs {

// TODO: 战斗引擎逻辑未定，暂全部抛 not implemented，避免被误认为已可用。

void BattleEngine::init() {
    throw std::runtime_error("BattleEngine::init: not implemented yet");
}

bool BattleEngine::is_over() const {
    throw std::runtime_error("BattleEngine::is_over: not implemented yet");
}

void BattleEngine::begin_tick_timing() {
    throw std::runtime_error("BattleEngine::begin_tick_timing: not implemented yet");
}

void BattleEngine::exchange_state_buffers() {
    throw std::runtime_error("BattleEngine::exchange_state_buffers: not implemented yet");
}

void BattleEngine::compute_next(const std::vector<InputEvent>& /*inputs*/) {
    throw std::runtime_error("BattleEngine::compute_next: not implemented yet");
}

void BattleEngine::wait_until_tick_end() const {
    throw std::runtime_error("BattleEngine::wait_until_tick_end: not implemented yet");
}

BattleSnapshot BattleEngine::get_snapshot() const {
    throw std::runtime_error("BattleEngine::get_snapshot: not implemented yet");
}

}  // namespace srs
