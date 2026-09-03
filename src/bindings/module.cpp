#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include "srs/engine/battle_engine.hpp"
#include "srs/engine/battle_snapshot.hpp"
#include "srs/engine/input_event.hpp"
#include "srs/engine/team_engine.hpp"
#include "srs/engine/team_snapshot.hpp"

namespace py = pybind11;

// pybind 只导出产品边界：两个 engine + 领域快照 + 输入事件。
// cpp 内部状态 / 逻辑类型不暴露给 Python。
PYBIND11_MODULE(starrail_cpp_core_ng, m) {
    m.doc() = "star-rail-sim-ng C++ core";

    py::class_<srs::InputEvent>(m, "InputEvent")
        .def(py::init<>())
        .def(py::init<std::string>(), py::arg("code"))
        .def_readwrite("code", &srs::InputEvent::code);

    py::class_<srs::BattleSnapshot>(m, "BattleSnapshot")
        .def(py::init<>());

    py::class_<srs::TeamSnapshot>(m, "TeamSnapshot")
        .def(py::init<>());

    py::class_<srs::BattleEngine>(m, "BattleEngine")
        .def(py::init<>())
        .def("init", &srs::BattleEngine::init)
        .def("is_over", &srs::BattleEngine::is_over)
        .def("begin_tick_timing", &srs::BattleEngine::begin_tick_timing)
        .def("exchange_state_buffers", &srs::BattleEngine::exchange_state_buffers)
        .def("compute_next", &srs::BattleEngine::compute_next)
        .def("wait_until_tick_end", &srs::BattleEngine::wait_until_tick_end)
        .def("get_snapshot", &srs::BattleEngine::get_snapshot);

    py::class_<srs::TeamEngine>(m, "TeamEngine")
        .def(py::init<>())
        .def("init", &srs::TeamEngine::init)
        .def("is_over", &srs::TeamEngine::is_over)
        .def("compute_next", &srs::TeamEngine::compute_next)
        .def("get_snapshot", &srs::TeamEngine::get_snapshot);
}
