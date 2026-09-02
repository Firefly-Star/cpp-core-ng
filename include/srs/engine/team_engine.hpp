#pragma once

#include <string>

#include "srs/engine/input_event.hpp"
#include "srs/engine/team_snapshot.hpp"

namespace srs {

// TeamEngine：事件驱动的组队引擎。
//
// 内部状态机：选友方 → 选敌方 → 确认完成。
// Python 侧驱动（无时钟，按一个键处理一个）：
//   while not is_over():
//       key = inputter.read_key_blocking()
//       compute_next(key)
//       snap = get_snapshot()
//       renderer.render(presenter(snap))
class TeamEngine {
public:
    // 初始化组队流程。
    // TODO: 候选图鉴来源未定（cpp 侧 json 读取方式后续定），暂为无参。
    void init();

    bool is_over() const;

    // 事件驱动：接收单个输入事件，更新选择 / 阶段状态。
    void compute_next(const InputEvent& event);

    // 只读领域快照（当前选择状态），供 presenter 翻译成视图语义。
    TeamSnapshot get_snapshot() const;

    // TODO(后续): 组队完成后的阵容产出（交给 BattleEngine）
    // 类型未定，暂不声明，后续按需补。

    // TODO(后续): 内部组队状态（候选池 / 已选 / 当前阶段等）
    // 在 state 头定义后补齐为私有成员。
};

}  // namespace srs
