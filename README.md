# cpp-core-ng

star-rail-sim-ng 的 C++ 核心子仓库。

定位：
- 战斗 engine / 组队 engine
- 纯领域状态与规则（不知道 Python / UI / 布局）
- 给每个领域一个状态快照类型用于 C++ ↔ Python 通讯

## 目录结构（按老 cpp-core 布局）

```text
include/srs/engine/   BattleEngine / TeamEngine 边界
include/srs/state/    领域状态（待建）
include/srs/logic/    纯结算逻辑（待建）
src/engine/           引擎实现（待建）
src/logic/            逻辑实现（待建）
src/bindings/         pybind 边界导出（待建）
```

## 当前状态

- `include/srs/engine/battle_engine.hpp` — 时钟驱动战斗引擎骨架
- `include/srs/engine/team_engine.hpp` — 事件驱动组队引擎骨架
- `include/srs/engine/battle_snapshot.hpp` / `team_snapshot.hpp` — 领域快照（空结构体，待填字段）
- config 相关（阵容/图鉴来源）尚未确定，暂不声明，后续按需补
- 命名空间：`srs`（沿用旧仓库；可调整）
