// %BANNER_BEGIN%
// ---------------------------------------------------------------------
// %COPYRIGHT_BEGIN%
//
// Copyright (c) 201x Magic Leap, Inc. (COMPANY) All Rights Reserved.
// Magic Leap, Inc. Confidential and Proprietary
//
// NOTICE: All information contained herein is, and remains the property
// of COMPANY. The intellectual and technical concepts contained herein
// are proprietary to COMPANY and may be covered by U.S. and Foreign
// Patents, patents in process, and are protected by trade secret or
// copyright law. Dissemination of this information or reproduction of
// this material is strictly forbidden unless prior written permission is
// obtained from COMPANY. Access to the source code contained herein is
// hereby forbidden to anyone except current COMPANY employees, managers
// or contractors who have executed Confidentiality and Non-disclosure
// agreements explicitly covering such access.
//
// The copyright notice above does not evidence any actual or intended
// publication or disclosure of this source code, which includes
// information that is confidential and/or proprietary, and is a trade
// secret, of COMPANY. ANY REPRODUCTION, MODIFICATION, DISTRIBUTION,
// PUBLIC PERFORMANCE, OR PUBLIC DISPLAY OF OR THROUGH USE OF THIS
// SOURCE CODE WITHOUT THE EXPRESS WRITTEN CONSENT OF COMPANY IS
// STRICTLY PROHIBITED, AND IN VIOLATION OF APPLICABLE LAWS AND
// INTERNATIONAL TREATIES. THE RECEIPT OR POSSESSION OF THIS SOURCE
// CODE AND/OR RELATED INFORMATION DOES NOT CONVEY OR IMPLY ANY RIGHTS
// TO REPRODUCE, DISCLOSE OR DISTRIBUTE ITS CONTENTS, OR TO MANUFACTURE,
// USE, OR SELL ANYTHING THAT IT MAY DESCRIBE, IN WHOLE OR IN PART.
//
// %COPYRIGHT_END%
// --------------------------------------------------------------------
// %BANNER_END%

#include <ml_perception.h>
#include <ml_lifecycle.h>
#include <ml_logging.h>

int main() {
  MLLifecycleCallbacksEx callbacks{};
  MLLifecycleInitEx(&callbacks, nullptr);
  MLPerceptionSettings settings;
  MLPerceptionInitSettings(&settings);
  ML_LOG_TAG(Info, "SimpleNativeApp", "Hello, world, from SimpleNativeApp!");

  // Print optional initialization string passed via 'mldb launch'
  MLLifecycleInitArgList* list = nullptr;
  MLResult result = MLLifecycleGetInitArgList(&list);
  if ((MLResult_Ok == result) && (nullptr != list)) {
    int64_t list_length = 0;
    result = MLLifecycleGetInitArgListLength(list, &list_length);
    if ((MLResult_Ok == result) && (list_length > 0)) {
      const MLLifecycleInitArg* iarg = nullptr;
      result = MLLifecycleGetInitArgByIndex(list, 0, &iarg);
      if ((MLResult_Ok == result) && (nullptr != iarg)) {
        const char* uri = nullptr;
        result = MLLifecycleGetInitArgUri(iarg, &uri);
        if ((MLResult_Ok == result) && (nullptr != uri)) {
          ML_LOG_TAG(Info, "SimpleNativeApp", "%s", uri);
        }
      }
    }
    MLLifecycleFreeInitArgList(&list);
  }

  MLLifecycleSetReadyIndication();
  return 0;
}
