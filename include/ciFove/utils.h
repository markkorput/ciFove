#pragma once

#include <iostream>
#include "FoveTypes.h"

namespace cinder { namespace fove {

  // Helper function to throw an exception if the passed error code is not None
  inline bool CheckError(const Fove::EFVR_ErrorCode code, const char* const data)
  {
    if (code == Fove::EFVR_ErrorCode::None) return false;
    // throw std::runtime_error("Unable to get " + std::string(data) + ": " + std::to_string(static_cast<int>(code)));
    std::cerr
      << "[ciFove] Unable to get " << data
      << ": " << static_cast<int>(code)
      << std::endl;
    return true;
  }

  // // Helper function, which will throw if the result of a Fove call returns error
  // // Use like this: const auto MyObject = CheckError(Fove->GetSomeObject(...));
  // // This works on any function that returns an error via a .error field in the return object
  // template <typename Type>
  // Type&& CheckError(Type&& object, const char* const data)
  // {
  // 	CheckError(object.error, data);
  // 	return std::move(object);
  // }

}}
