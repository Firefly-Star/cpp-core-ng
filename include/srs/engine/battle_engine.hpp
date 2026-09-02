#pragma once

#include <string>
#include <vector>

#include "srs/engine/battle_snapshot.hpp"
#include "srs/engine/input_event.hpp"

namespace srs {

// BattleEngine：时钟驱动的战斗引擎（cpp ↔ Python 通讯边界门面）。
//
// Python 侧按 tick phase 驱动：
//   engine.begin_tick_timing()
//   inputs = inputter.cutoff()
//   engine.exchange_state_buffers()
//   snap = engine.get_snapshot()
//   engine.compute_next(inputs)
//   engine.wait_until_tick_end()
class BattleEngine {
public:
    // 初始化一场战斗。
    // TODO: 阵容来源未定（将由组队结果给出），暂为无参，后续按需补。
    void init();

    bool is_over() const;

    // —— 时钟驱动 tick phase ——
    void begin_tick_timing();
    void exchange_state_buffers();

    // 消费本 tick 截断的输入事件批次，计算下一状态。
    void compute_next(const std::vector<InputEvent>& inputs);

    void wait_until_tick_end() const;

    // 只读领域快照（由内部状态投影），供 presenter 翻译成视图语义。
    BattleSnapshot get_snapshot() const;

    // TODO(后续): 内部战斗状态（行动轴 / 轴顶 / 资源等）
    // 在 state 头定义后补齐为私有成员。
};

}  // namespace srs
