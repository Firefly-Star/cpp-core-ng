#include "srs/engine/team_engine.hpp"

#include <stdexcept>

namespace srs {

// TODO: 组队引擎逻辑未定，暂全部抛 not implemented，避免被误认为已可用。

void TeamEngine::init() {
    throw std::runtime_error("TeamEngine::init: not implemented yet");
}

bool TeamEngine::is_over() const {
    throw std::runtime_error("TeamEngine::is_over: not implemented yet");
}

void TeamEngine::compute_next(const InputEvent& /*event*/) {
    throw std::runtime_error("TeamEngine::compute_next: not implemented yet");
}

TeamSnapshot TeamEngine::get_snapshot() const {
    throw std::runtime_error("TeamEngine::get_snapshot: not implemented yet");
}

}  // namespace srs
