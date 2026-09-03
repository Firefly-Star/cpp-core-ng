#pragma once

#include <string>
#include <utility>

namespace srs {

// 一次输入事件：engine 的输入契约类型。
// code：按键码，如 "1" / "q" / "\r"(回车) / "\x03"(Ctrl+C)。
// 后续如需区分设备(kind)/时间戳等再补字段。
struct InputEvent {
    std::string code;

    InputEvent() = default;
    explicit InputEvent(std::string code_) : code(std::move(code_)) {}
};

}  // namespace srs
