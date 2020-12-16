/*
 *  Copyright (c) Facebook, Inc. and its affiliates.
 */

#pragma once

#include <stdio.h>

#include <vector>

#include "absl/types/optional.h"
#include "rtc_base/bit_buffer.h"

namespace h265nal {

// A class for parsing out a video sequence parameter set (AUD) data from
// an H265 NALU.
class H265AudParser {
 public:
  // The parsed state of the AUD.
  struct AudState {
    AudState() = default;
    AudState(const AudState&) = default;
    ~AudState() = default;
#ifdef FDUMP_DEFINE
    void fdump(FILE* outfp, int indent_level) const;
#endif  // FDUMP_DEFINE

    uint32_t pic_type = 0;
  };

  // Unpack RBSP and parse AUD state from the supplied buffer.
  static absl::optional<AudState> ParseAud(const uint8_t* data,
                                           size_t length) noexcept;
  static absl::optional<AudState> ParseAud(rtc::BitBuffer* bit_buffer) noexcept;
};

}  // namespace h265nal
