#include "MaaFwAdbController.h"

namespace asst
{
bool MaaFwAdbController::connect(
    const std::string& adb_path,
    const std::string& address,
    const std::string& config)
{
    return connect_with_extras(
        adb_path,
        address,
        config,
        json::object {
            { "library_name", "MaaAdbControlUnit" },
            // AdbShell 输入的 touch_down/move/up 是空实现且不上报
            // UseMouseDownAndUpInsteadOfClick，会导致 swipe 退化为 `input swipe`，
            // 额外滑动（extra_swipe）被丢弃。指定 Maatouch 输入以启用精确滑动路径
            // （extra_swipe / slope_in / slope_out / with_pause 全部生效）。
            { "input_methods", MaaAdbInputMethod::Maatouch },
        });
}
} // namespace asst
